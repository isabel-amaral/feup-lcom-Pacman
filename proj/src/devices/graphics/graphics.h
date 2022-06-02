#ifndef _LCOM_GRAPHICS_H_
#define _LCOM_GRAPHICS_H_

int (graphics_init)(uint16_t mode);

int (map_vram)(uint16_t mode);

int (initialize_graphics_mode)(uint16_t mode);

int (verify_screen_limits)(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

void (draw_pixel)(uint16_t x, uint16_t y, uint32_t color);

void (draw_line)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);

void (draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

void (initialize_pixmap)(xpm_map_t xpm);

void (draw_xpm)(uint16_t x, uint16_t y);

void (move_xpm)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, uint16_t* x, uint16_t* y, int16_t speed);

#endif
