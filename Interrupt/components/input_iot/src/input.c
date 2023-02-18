#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "input.h"


input_callback_t input_callback = NULL;

static void IRAM_ATTR gpio_input_handler(void* arg)
{
    int gpio_num = (uint32_t) arg;
    input_callback(gpio_num);
}


void INPUT_io_create(gpio_num_t gpio_num, gpio_int_type_t level)
{
    gpio_config_t IO_config; 
    IO_config.pin_bit_mask = (1<<gpio_num);          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    IO_config.mode = GPIO_MODE_INPUT;               /*!< GPIO mode: set input/output mode                     */
    IO_config.pull_up_en = GPIO_PULLUP_ENABLE;       /*!< GPIO pull-up                                         */
    IO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;   /*!< GPIO pull-down                                       */
    IO_config.intr_type = level;      /*!< GPIO interrupt type                                  */ 
    gpio_install_isr_service(0);
    gpio_isr_handler_add(gpio_num, gpio_input_handler, (void *)gpio_num);
    gpio_config(&IO_config);

}


void INPUT_set_callback(void *call_back)
{
    input_callback = call_back;
}