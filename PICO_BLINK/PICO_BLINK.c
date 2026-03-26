#include <stdio.h>
#include "pico/stdlib.h"

#define LEDPIN 25U

int main() {
    gpio_init(LEDPIN);
    gpio_set_dir(LEDPIN, GPIO_OUT);
    
    while(true) {

        gpio_put(LEDPIN, 1);
        sleep_ms(500);

        gpio_put(LEDPIN, 0);
        sleep_ms(500);

    }
}