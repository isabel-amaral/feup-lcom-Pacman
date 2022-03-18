#include <lcom/lcf.h>

#include <stdint.h>

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}

/* To be implemented by the students */
int (util_sys_inb)(int port, uint8_t *value) {
  uint32_t* value_32 = (uint32_t*) malloc(sizeof(uint32_t));
  if (sys_inb(port, value_32) == 0) {
      uint32_t mask = 0x000000ff;
      *value = (uint8_t) (mask & *value_32);
      return 0;
  }

  else 
    return 1;
}
