#ifndef _LCOM_MOUSE_H_
#define _LCOM_MOUSE_H_

int (mouse_subscribe_int)(uint8_t *bit_no);

int (mouse_unsubscribe_int)();

int (enable_data_reporting)();

int (disable_data_reporting)();

void (mouse_int_handler)();

void (parse_mouse_packet)(struct packet* pp);

#endif
