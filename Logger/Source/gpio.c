#include "gpio.h"
#include "PJ_RPI.h"

extern struct bcm2835_peripheral gpio;

void GPIO_Init(int pin, int mode)
{
  INP_GPIO(pin);
  if (mode == 1)
    OUT_GPIO(pin);
}

int GPIO_Read(int pin)
{
  INP_GPIO(pin);
  return GPIO_READ(pin);
}

int GPIO_Log(int pin, int prev)
{
  int value = GPIO_Read(pin);
  if (value != prev)
    printf("GPIO %d is %s\n", pin, value ? "HIGH" : "LOW");
  return value;
}