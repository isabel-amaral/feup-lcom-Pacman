#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#include <lcom/lcf.h>

#define DELAY_US 20000
#define INT_PER_SEC 60

#define KEYBOARD_IRQ 1
#define MOUSE_IRQ 12

#define OUT_BUF_REG 0x60
#define ST_REG 0x64
#define KBC_CMD_REG 0x64
#define READ_CMD 0x20
#define WRITE_CMD 0x60
#define WRITE_MOUSE_BYTE 0xD4

//mouse commands
#define ENABLE_DATA 0xF4
#define DISABLE_DATA 0xF5
#define ACK 0xF4
#define NACK 0xFE
#define ERROR 0xFC

#define OBF BIT(0)
#define IBF BIT(1)
#define PAR_ERR BIT(7)
#define TO_ERR BIT(6)

// value of the most significant byte if the scanecode has 2 bytes
#define SCAN_MSB 0xE0

#define ESC_CODE 0x81

#endif
