#include <lcom/lcf.h>

void *(vg_init)(uint16_t mode);

int map_vram(uint16_t mode);

int initialize_graphics_mode(uint16_t mode);

int verify_screen_limits(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

int (vg_draw_pixel)(uint16_t x, uint16_t y, uint32_t color);

int (vg_draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);

int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
