#ifndef TIMER_CONTROLLER_H
#define TIMER_CONTROLLER_H

void initialize_game_time();

void timer_interrupt_handler();

void decrease_game_time();

void pause_game();

void continue_game();

void increase_time();

void check_time_out();

#endif
