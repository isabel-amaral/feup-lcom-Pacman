#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/graphics/vbe.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/coins_model/coin.h"
#include "../initialize_pixmaps.h"
#include "coins_view.h"

extern SmallCoin small_coins[400];
extern uint8_t* small_coin_pixmap;
extern xpm_image_t small_coin_info;

void (draw_small_coins)() {
    for(int i = 0; i < 400; i++)
        draw_xpm(small_coin_pixmap, small_coin_info, small_coins[i].pos.left_x, small_coins[i].pos.top_y);
}

void (erase_small_coins)() {
    for(int i = 0; i < 400; i++)
        draw_rectangle(small_coins[i].pos.left_x, small_coins[i].pos.top_y, small_coin_info.width, small_coin_info.height, BACKGROUND);
}
