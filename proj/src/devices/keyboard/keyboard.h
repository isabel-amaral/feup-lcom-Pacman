#ifndef _LCOM_KEYBOARD_H_
#define _LCOM_KEYBOARD_H_

int (keyboard_subscribe_int)(uint8_t* bit_no);

int (keyboard_unsubscribe_int)();

void (keyboard_int_handler)();

int (kbc_enable_int)();

#endif
