#include "PJ_RPI.h"
#include <stdio.h>
#include "gpio.h"

int gpio_17_val = -1;

int main()
{
	if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	GPIO_Init(17, 0); // Set GPIO 17 as input

	while (1)
	{
		gpio_17_val = GPIO_Log(17, gpio_17_val);
		sleep(3);
	}

	return 0;
}