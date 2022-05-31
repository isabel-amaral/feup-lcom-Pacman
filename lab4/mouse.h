#ifndef MOUSE_H
#define MOUSE_H

int (mouse_subscribe_int)();

int (mouse_unsubscribe_int)();

int (enable_data_reporting)();

int (disable_data_reporting)();

void (mouse_ih)();

void (parse_mouse_packet)();

#endif
