#include "timer_controller.h"

#include <stdint.h>

float game_time_minutes;
unsigned int game_time_seconds;
unsigned int seconds_before_pause;
float minutes_before_pause;
extern unsigned int int_counter;
extern bool game_is_on;

void initialize_game_time() {
    game_time_minutes = 2;
    game_time_seconds = 120;
}

void timer_interrupt_handler() {
    timer_int_handler();
    if (int_counter%60 == 0)
        decrease_game_time();
}

void decrease_game_time() {
    game_time_seconds--;
    game_time_minutes -= 0.01;
    check_time_out();
}

void pause_game() {
    seconds_before_pause = game_time_seconds;
    minutes_before_pause= game_time_minutes;
}

void continue_game() {
    game_time_seconds = seconds_before_pause;
    game_time_minutes = minutes_before_pause;
}

void increase_time() {
    game_time_seconds += 30;
    game_time_minutes += 0.30;
}

void check_time_out() {
    if (game_time_seconds == 0) 
        game_is_on = false;
}
