#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

void (check_button)(bool clicked);

void (update_cursor)(struct packet pp);

void (mouse_interrupt_handler)();

#endif
