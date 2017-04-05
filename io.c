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

void
io_write(uint8_t val)
{
	// active low
	
#define io_bitset(BitStatus, Port, Pin) do { \
	void (*pfnGpioWrite)(GPIO_TypeDef*, GPIO_Pin_TypeDef) = &GPIO_WriteHigh; \
	if (!!(BitStatus)) pfnGpioWrite = &GPIO_WriteLow; \
	pfnGpioWrite((Port), (Pin)); \
} while (0)

	io_bitset(val & (1 << 0), GPIOD, GPIO_PIN_3);
	io_bitset(val & (1 << 1), GPIOD, GPIO_PIN_2);
	io_bitset(val & (1 << 2), GPIOC, GPIO_PIN_3);
	io_bitset(val & (1 << 3), GPIOA, GPIO_PIN_3);
}
