#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdint.h>

typedef void (*input_callback_t)(int);

void INPUT_io_create(gpio_num_t gpio_num, gpio_int_type_t level);
void INPUT_set_callback(void *cal_back);

#endif