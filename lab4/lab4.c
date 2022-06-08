// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>
#include <lcom/lab4.h>

#include "mouse.h"
#include "timer.c"
#include "i8042.h"

#include <stdint.h>
#include <stdio.h>

extern int packet_index;
extern uint8_t packet_bytes[3];
extern unsigned int int_counter;

// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int (mouse_test_packet)(uint32_t cnt) {
  if (enable_data_reporting() != 0)
    return 1;
  if (mouse_subscribe_int() != 0)
    return 1;

  message msg;
  int ipc_status, r, irq_set = BIT(MOUSE_IRQ);
  packet_index = 0;

  while(cnt != 0) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
        printf("driver_receive failed with: %d", r);
        continue;
    }
    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:				
            if (msg.m_notify.interrupts & irq_set) {
              mouse_ih();
              if (packet_index == 3) {
                struct packet pp;
                parse_mouse_packet(&pp);
                mouse_print_packet(&pp);
                packet_index = 0;
                cnt--;
              }
            }
            break;
        default:
            break;
      }
    }  
  }

  if (mouse_unsubscribe_int() != 0) 
    return 1;
  if (disable_data_reporting() != 0)
    return 1;      
  return 0;
}

int (mouse_test_async)(uint8_t idle_time) {
    uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
    timer_subscribe_int(bit_no);
    uint32_t irq_set_timer = BIT(*bit_no);

    if (mouse_enable_data_reporting() != 0)
      return 1;
    if (mouse_subscribe_int() != 0)
      return 1;

    message msg;
    int ipc_status, r, irq_set_mouse = BIT(MOUSE_IRQ);
    packet_index = 0;
    int_counter = 0;

    while (int_counter != idle_time*(uint32_t)sys_hz()) {
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
      if (is_ipc_notify(ipc_status)) {
        switch (_ENDPOINT_P(msg.m_source)) {
          case HARDWARE:				
              if (msg.m_notify.interrupts & irq_set_mouse) {
                int_counter = 0;
                mouse_ih();
                if (packet_index == 3) {
                  struct packet pp;
                  parse_mouse_packet(&pp);
                  mouse_print_packet(&pp);
                  packet_index = 0;
                }
              }
              if (msg.m_notify.interrupts & irq_set_timer)
                timer_int_handler();
              break;
          default:
              break;
        }
      }  
    }

    if (timer_unsubscribe_int() != 0)
      return 1;
    if (mouse_unsubscribe_int() != 0) 
      return 1;
    if (disable_data_reporting() != 0)
      return 1;      
    return 0;
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
    /* To be completed */
    printf("%s: under construction\n", __func__);
    return 1;
}

int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    /* This year you need not implement this. */
    printf("%s(%u, %u): under construction\n", __func__, period, cnt);
    return 1;
}
