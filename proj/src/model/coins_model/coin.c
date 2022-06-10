#include "coin.h"

Coin small_coins[200];
BigCoin big_coins[5];

void set_coins_position() {
    for(int c = 0; c < 15; c++) {
        for(int i = 195; i < 480; i+= 19) {
            small_coins[c].pos.left_x = i;
            small_coins[c].pos.right_x = i + 25;
            small_coins[c].pos.top_y = 65;
            small_coins[c].pos.bottom_y = 90;
        }
    }
}
