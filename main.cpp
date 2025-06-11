#include "lv_drv_conf.h"
#include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/lvgl.h"
#include "ui.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h" 

int main() {
  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

  lv_demo_widgets();
  // lv_demo_keypad_encoder();
  // lv_demo_benchmark();
  // lv_demo_stress();
  // lv_demo_music();

  // user_image_demo();

  // mygui();
  while (1) {
    
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_timer_handler();
    usleep(5 * 1000);
  }

  hal_deinit();
  return 0;
}