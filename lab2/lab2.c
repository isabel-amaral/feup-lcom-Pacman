#include <lcom/lcf.h>
#include <lcom/lab2.h>

#include <stdbool.h>
#include <stdint.h>
extern unsigned int int_counter;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab2/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab2/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(timer_test_read_config)(uint8_t timer, enum timer_status_field field) {
  uint8_t* st = (uint8_t*) malloc(sizeof(uint8_t));

  if (timer_get_conf(timer, st) != 0){
    printf ("Failed timer_get_conf\n");
    return 1;
  }

  if (timer_display_conf(timer, *st, field) != 0){
    printf ("Failed timer_display_conf\n");
    return 1;
  }

  printf("Success\n");
  return 0;
}

int(timer_test_time_base)(uint8_t timer, uint32_t freq) {
  if (timer_set_frequency(timer, freq) != 0){
    printf("Failed timer_set_frequency\n");
    return 1;
  }

  printf("Success\n");
  return 0;
}

int(timer_test_int)(uint8_t time) {
  uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (timer_subscribe_int(bit_no) != 0) {
    printf("Failed timer_subscribe_int\n");
    return 1;
  }

  // The number os interrupts per second
  uint32_t timer0_int_freq = 60;
  /*To make sure the time is being counted in the right way*/
  if (timer_set_frequency(0, timer0_int_freq) != 0) {
    timer_unsubscribe_int();
    printf("Failed timer_set_frequency\n");
    return 1;
  }

  uint32_t irq_set = BIT(*bit_no);
  int ipc_status, r;
  message msg;
  int counter = 0;
  
  while(counter != time) {
    if((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
        if (msg.m_notify.interrupts & irq_set)
          timer_int_handler();
        break;
        default:
          break;
      }

      if (int_counter%60 == 0) {
        counter++;
        timer_print_elapsed_time();
      }
    }
  }
    
  if (timer_unsubscribe_int() != 0) {
    printf("Failed timer_unsubscribe_int\n");
    return 1;
  }
  printf("Success\n");
  return 1;
}
