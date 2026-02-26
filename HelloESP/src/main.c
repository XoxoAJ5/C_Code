#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define RED_PIN 4
#define GREEN_PIN 5

typedef struct main {
    int state_red;
    int state_green;
    int time;
} ColorStep;

void applycolor(ColorStep *step) {
    gpio_set_level(RED_PIN, step->state_red);
    gpio_set_level(GREEN_PIN, step->state_green);
    vTaskDelay(step->time/portTICK_PERIOD_MS);
}


void app_main(void) {

    gpio_reset_pin(RED_PIN);
    gpio_set_direction(RED_PIN, GPIO_MODE_OUTPUT);
    gpio_reset_pin(GREEN_PIN);
    gpio_set_direction(GREEN_PIN, GPIO_MODE_OUTPUT);

    ColorStep sequence[] = {{1,0,1000}, {0,1,1000}, {1,1, 500}, {0,0,500}};
    printf("starting led sequence\n");

    int num_steps = sizeof(sequence)/sizeof(sequence[0]);
    while(1){
        for(int i = 0; i < num_steps; i++) {
            applycolor(&sequence[i]);
        }
    }
}