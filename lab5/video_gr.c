#include <lcom/lcf.h>
#include <lcom/lab5.h>

#include "math.h"
#include "video_gr.h"

#define AH 0x4f
#define VBE_FUNCTION 0x02
#define INT_NO 0x10

#define RED_115 0xFF0000
#define GREEN_115 0x00FF00
#define BLUE_115 0x0000FF
#define BLACK_105 0x00

vbe_mode_info_t* vmi_p;
void* video_mem;
int vg_init_success;
int indexed_color_mode;

int map_vram(uint16_t mode) {
  int r;
  struct minix_mem_range mr; /* physical memory range */
  
  vmi_p = (vbe_mode_info_t*) malloc(sizeof(vbe_mode_info_t));
  if (vbe_get_mode_info(mode, vmi_p) != 0)
    return 1;
  switch (mode) {
  case 0x105:
    indexed_color_mode = 1;
    break;
  case 0x115:
    indexed_color_mode = 0;
    break;
  default:
    vg_exit();
    printf("Mode is not supported\n");
    return 1;
  }

  unsigned int vram_base = vmi_p->PhysBasePtr; /* VRAM’s physical addresss */
  unsigned int vram_size = vmi_p->XResolution * vmi_p->YResolution * ceil(vmi_p->BitsPerPixel / (double) 8); /* VRAM’s size, but you can use the frame-buffer size, instead */

  /* Allow memory mapping */
  mr.mr_base = (phys_bytes) vram_base;
  mr.mr_limit = mr.mr_base + vram_size;

  if ( OK != (r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mr)))
    panic("sys_privctl (ADD_MEM) failed: %d\n", r);
  /* Map memory */
  video_mem = vm_map_phys(SELF, (void *)mr.mr_base, vram_size);
  if (video_mem == MAP_FAILED)
    panic("couldn’t map video memory");
  return 0;
}

int initialize_graphics_mode(uint16_t mode) {
  reg86_t r;

  memset(&r, 0, sizeof(r));
  r.ah = AH;
  r.al = VBE_FUNCTION;
  r.bx = BIT(14)|mode;
  r.intno = INT_NO;
  if (sys_int86(&r) != OK) {
    printf("set_vbe_mode: sys_int86() failed \n");
    return 1;
  }
  return 0;
}

void* (vg_init)(uint16_t mode) {
  if (map_vram(mode) != 0)
    vg_init_success = 1;
  if (initialize_graphics_mode(mode) != 0)
    vg_init_success = 1;
  vg_init_success = 0;
  return video_mem;
}

int verify_screen_limits(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
  if (x > vmi_p->XResolution) {
    vg_exit();
    printf("X is out of range\n");
    return 1;
  }
  if (y > vmi_p->YResolution) {
    vg_exit();
    printf("Y is out of range\n");
    return 1;
  }
  if (x + width  > vmi_p->XResolution) {
    vg_exit();
    printf("Width is out of range\n");
    return 1;
  }
  if (y + height  > vmi_p->YResolution) {
    vg_exit();
    printf("Height is out of range\n");
    return 1;
  }
  return 0;
}

int vg_draw_pixel(uint16_t x, uint16_t y, uint32_t color) {
  size_t num_bytes = ceil(vmi_p->BitsPerPixel / (double) 8);
  char* address = (char*) video_mem;
  address += (y*vmi_p->XResolution+x)*num_bytes;
  memcpy(address, &color, num_bytes);

  return 0;
}

int (vg_draw_hline)(uint16_t x, uint16_t y, uint16_t width, uint32_t color) {
  for (int i = x; i < x + width; i++) {
    if (vg_draw_pixel(i, y, color) != 0)
      return 1;
  }
  return 0;
}

int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) {
  for (int i = y; i < y + height; i++)
    if (vg_draw_hline(x, i, width, color) != 0)
      return 1;
  return 0;
}

int (vg_draw_pattern)(uint8_t no_rectangles, uint32_t first, uint8_t step) {
  uint32_t width, height, x = 0, y = 0;
  width = floor(vmi_p->XResolution / no_rectangles);
  height = floor(vmi_p->YResolution / no_rectangles);

  for (int i = 0; i < no_rectangles; i++) {
    x = 0;
    y = i*height;
    for (int j = 0; j < no_rectangles; j++) {
      x = j*width;

      uint32_t color = 0;
      if (indexed_color_mode)
        color = (first + (j * no_rectangles + i) * step) % (1 << vmi_p->BitsPerPixel);
      else {
        uint32_t R_first = (first & RED_115) >> vmi_p->RedFieldPosition;
        uint32_t G_first = (first & GREEN_115) >> vmi_p->GreenFieldPosition;
        uint32_t B_first = (first & BLUE_115) >> vmi_p->BlueFieldPosition;

        color |= (R_first + i * step) % (1 << vmi_p->RedMaskSize);
        color <<= 8;
        color |= (G_first + j * step) % (1 << vmi_p->GreenMaskSize);
        color <<= 8;
        color |= (B_first + (i + j) * step) % (1 << vmi_p->BlueMaskSize);
      }
      
      if (vg_draw_rectangle(x, y, width, height, color) != 0)
        return 1;
    }
  }
  return 0;
}

int (vg_draw_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
  xpm_image_t* img = (xpm_image_t*) malloc(sizeof(xpm_image_t));
  uint8_t* pixmap = xpm_load(xpm, XPM_INDEXED, img);

  for (int i = y; i < y + img->height; i++) {
    for (int j = x; j < x + img->width; j++) {
      vg_draw_pixel(j, i, *pixmap);
      pixmap++;
    }
  }
  return 0;
}

int (vg_move_xpm)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, uint16_t* x, uint16_t* y, int16_t speed) {
  if ((xi < xf && *x < xf) || (xi > xf && *x > xf) || 
      (yi < yf && *y < yf) || (yi > yf && *y > yf)) {
    if (vg_draw_rectangle(0, 0, vmi_p->XResolution, vmi_p->YResolution, BLACK_105) != 0)
      return 1;
    if (vg_draw_xpm(xpm, *x, *y) != 0)
      return 1;
  }

  if (xi < xf && *x < xf)
    *x += speed;
  if (xi > xf && *x > xf)
    *x -= speed;
  if (yi < yf && *y < yf)
    *y += speed;
  if (yi > yf && *y > yf)
    *y -= speed;
  return 0;
}
