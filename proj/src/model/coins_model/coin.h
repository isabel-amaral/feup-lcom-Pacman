#ifndef COIN_MODEL_H
#define COIN_MODEL_H

#include "../position.h"

typedef struct {
    Position pos;
} SmallCoin;

typedef struct {
    Position pos;
} BigCoin;

void (set_coins_position)();

#endif
