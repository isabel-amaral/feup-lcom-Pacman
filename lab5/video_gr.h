#include <lcom/lcf.h>

void *(vg_init)(uint16_t mode);

int map_vram(uint16_t mode);

int initialize_graphics_mode(uint16_t mode);

int verify_screen_limits(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

int vg_draw_pixel(uint16_t x, uint16_t y, uint32_t color);

int (vg_draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);

int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

int (vg_draw_pattern)(uint8_t no_rectangles, uint32_t first, uint8_t step);

void (vg_initialize_pixmap)(xpm_map_t xpm);

int (vg_draw_xpm)(uint16_t x, uint16_t y);

int (vg_move_xpm)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, uint16_t* x, uint16_t* y, int16_t speed);
