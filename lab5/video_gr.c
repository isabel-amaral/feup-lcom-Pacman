#include <lcom/lcf.h>
#include <lcom/lab5.h>

#include "video_gr.h"

#define AH 0x4f
#define VBE_FUNCTION 0x02
#define INT_NO 0x10

void *video_mem;
int vg_init_success;

int map_vram(uint16_t mode) {
  vbe_mode_info_t* vmi_p = (vbe_mode_info_t*) malloc(sizeof(vbe_mode_info_t));
  if (vbe_get_mode_info(mode, vmi_p) != 0)
    return 1;

  int r;
  struct minix_mem_range mr; /* physical memory range */
  unsigned int vram_base = vmi_p->PhysBasePtr; /* VRAM’s physical addresss */
  unsigned int vram_size = vmi_p->XResolution * vmi_p->YResolution * vmi_p->BitsPerPixel; /* VRAM’s size, but you can use the frame-buffer size, instead */

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
  vbe_mode_info_t* vmi_p = (vbe_mode_info_t*) malloc(sizeof(vbe_mode_info_t));
  if (vbe_get_mode_info(mode, vmi_p) != 0)
    return 1;

  if (x >= vmi_p->XResolution) {
    printf("X is out of range\n");
    return 1;
  }
  if (y >= vmi_p->YResolution) {
    printf("Y is out of range\n");
    return 1;
  }
  if (x + width  >= vmi_p->XResolution) {
    printf("Width is out of range\n");
    return 1;
  }
  if (y + height  >= vmi_p->YResolution) {
    printf("Height is out of range\n");
    return 1;
  }
  return 0;
}
