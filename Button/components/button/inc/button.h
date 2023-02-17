#ifndef BUTTON_H
#define BUTTON_H

#define CLOCKS_PER_SEC  1000000

#include <stdio.h>
#include "esp_err.h"
#include "hal/gpio_types.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "time.h"


void BUTTON_Handle();

#endif