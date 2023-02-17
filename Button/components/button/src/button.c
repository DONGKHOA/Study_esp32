#include "button.h"

uint8_t current_state = 1;
uint8_t last_state = 1;
uint8_t deboucing_state = 1;
uint8_t is_deboucing = 0;
uint32_t deboucing_timer = 0;

void BUTTON_Handle(gpio_num_t gpio_num_button, gpio_num_t gpio_num_output)
{
    // detecting
    uint8_t temp_state = gpio_get_level(gpio_num_button);
	if(temp_state != deboucing_state)
	{
		deboucing_state = temp_state;
		deboucing_timer = clock();
		is_deboucing = 1;
	}

    // debouncing

	if(is_deboucing == 1 && (clock() - deboucing_timer) > 15)
	{
		current_state = deboucing_state;
		is_deboucing = 0;
	}
    
    if (current_state != last_state)
    {
        if (current_state == 0)
        {
            gpio_set_level(gpio_num_output, 1);
        }
        else
        {
            gpio_set_level(gpio_num_output, 0);
        }
        last_state = current_state;
    }
    
}