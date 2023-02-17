/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"


void app_main(void)
{
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<13);          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    GPIO_config.mode = GPIO_MODE_OUTPUT;               /*!< GPIO mode: set input/output mode                     */
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;       /*!< GPIO pull-up                                         */
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;   /*!< GPIO pull-down                                       */
    GPIO_config.intr_type = GPIO_INTR_DISABLE;      /*!< GPIO interrupt type                                  */

    gpio_config(&GPIO_config);

    uint8_t Led_state = 1;
    while (1)
    {
        gpio_set_level(13, Led_state);
        Led_state =! Led_state;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    
}
