#include "PJ_RPI.h"
#include <stdio.h>
#include "gpio.h"
#include "dblogger.h"

int gpio_26_val = -1;
int gpio_27_val = -1;

int main(int argc, char *argv[])
{
	if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	GPIO_Init(26, 0); // Set GPIO 26 as input
	GPIO_Init(27, 0); // Set GPIO 27 as input

	if (argc < 3)
	{
		printf("Usage: %s <username> <password>\n", argv[0]);
		return 1;
	}

	const char *user = argv[1];
	const char *pass = argv[2];

	// Initialize the database (replace with your actual credentials)
	if (!DB_Init("localhost", user, pass, "rpi_io_logger"))
	{
		printf("Database initialization failed!\n");
		return 1;
	}

	while (1)
	{
		if (GPIO_Log(26, &gpio_26_val))
			DB_Insert("gpio_log", 26, gpio_26_val);
		if (GPIO_Log(27, &gpio_27_val))
			DB_Insert("gpio_log", 27, gpio_27_val);
		sleep(1);
	}

	// Close the database connection
	DB_Close();

	return 0;
}