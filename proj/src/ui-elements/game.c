#include "game.h"
#include "maze.c"
#include "pacman.c"
#include "ghost.c"
#include "coin.c"


void set_game_elements() {
    Game game;
    game.maze = maze;
    game.pacman = pacman;
    game.ghosts = ghosts;
    game.coin = coin;
}
