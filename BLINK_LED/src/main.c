#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 14
#define BUTTON_GPIO 4

void app_main() {
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    gpio_config_t button_conf = {};

    button_conf.pin_bit_mask = (1ULL << BUTTON_GPIO);
    button_conf.mode = GPIO_MODE_INPUT;
    button_conf.pull_up_en = 1;
    button_conf.pull_down_en = 0;
    button_conf.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&button_conf);

    int count = 1;
    while(1) {
        int switch_state = gpio_get_level(BUTTON_GPIO);
        if(switch_state == 0){
            printf("Turning Led on %d\n", count);
            gpio_set_level(BLINK_GPIO, 1);
            count ++;
        } else {
            printf("Turning Led off\n");
            gpio_set_level(BLINK_GPIO, 0);
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}