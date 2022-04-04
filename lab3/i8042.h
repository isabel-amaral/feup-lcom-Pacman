#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#include <lcom/lcf.h>

#define DELAY_US 20000

#define KEYBOARD_IRQ 1

#define OUT_BUF_REG 0x60
#define ST_REG 0x64

#define OBF BIT(0)
#define PAR_ERR BIT(7)
#define TO_ERR BIT(6)

// value of the most significant byte if the scanecode has 2 bytes
#define SCAN_MSB 0xE0

#endif