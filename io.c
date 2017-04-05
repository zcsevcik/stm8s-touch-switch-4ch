#include "io.h"

void
io_init(void)
{
	GPIO_Init(GPIOC, GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4, GPIO_MODE_IN_FL_IT);
	GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_OD_HIZ_SLOW);
	EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_RISE_ONLY);
}

uint8_t
io_read(void)
{
	return (uint8_t)GPIO_ReadInputPin(GPIOC, GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4) >> 4;
}

static void
io_writepin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, BitStatus PinState)
{
	if (PinState == RESET)
	{
		GPIO_WriteLow(GPIOx, GPIO_Pin);
	}
	else
	{
		GPIO_WriteHigh(GPIOx, GPIO_Pin);
	}
}

void
io_write(uint8_t val)
{
	// active low
	io_writepin(GPIOD, GPIO_PIN_3, (BitStatus)!(val & (1<<0)));
	io_writepin(GPIOD, GPIO_PIN_2, (BitStatus)!(val & (1<<1)));
	io_writepin(GPIOC, GPIO_PIN_3, (BitStatus)!(val & (1<<2)));
	io_writepin(GPIOA, GPIO_PIN_3, (BitStatus)!(val & (1<<3)));
}
