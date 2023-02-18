#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "button.h"
#include "esp_timer.h"
#define pinButton GPIO_NUM_23
#define pinOutput GPIO_NUM_13

void config()
{
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<pinOutput);          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO*/
    GPIO_config.mode = GPIO_MODE_OUTPUT;               /*!< GPIO mode: set input/output mode                     */
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;       /*!< GPIO pull-up                                         */
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;   /*!< GPIO pull-down                                       */
    GPIO_config.intr_type = GPIO_INTR_DISABLE;      /*!< GPIO interrupt type                                  */
    gpio_config(&GPIO_config);

    GPIO_config.pin_bit_mask = (1<<pinButton);          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO*/
    GPIO_config.mode = GPIO_MODE_INPUT;               /*!< GPIO mode: set input/output mode                     */
    GPIO_config.pull_up_en = GPIO_PULLUP_ENABLE;       /*!< GPIO pull-up                                         */

    gpio_config(&GPIO_config);
}
void app_main(void)
{
    config();
    while (1)
    {
        BUTTON_Handle(pinButton, pinOutput);
    }
    
}
