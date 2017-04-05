#include "io.h"

#define IN_PINS     (GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4)
#define IN_PORT     (GPIOC)
#define IN_SHIFT    (4)

#define OUT1_PORT   (GPIOD)
#define OUT1_PIN    (GPIO_PIN_3)
#define OUT2_PORT   (GPIOD)
#define OUT2_PIN    (GPIO_PIN_2)
#define OUT3_PORT   (GPIOC)
#define OUT3_PIN    (GPIO_PIN_3)
#define OUT4_PORT   (GPIOA)
#define OUT4_PIN    (GPIO_PIN_3)

void
io_init(void)
{
	GPIO_Init(IN_PORT,   (GPIO_Pin_TypeDef)IN_PINS,  GPIO_MODE_IN_FL_IT);
	GPIO_Init(OUT1_PORT, (GPIO_Pin_TypeDef)OUT1_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(OUT2_PORT, (GPIO_Pin_TypeDef)OUT2_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(OUT3_PORT, (GPIO_Pin_TypeDef)OUT3_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
	GPIO_Init(OUT4_PORT, (GPIO_Pin_TypeDef)OUT4_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
}

uint8_t
io_read(void)
{
	return (uint8_t)GPIO_ReadInputPin(IN_PORT, (GPIO_Pin_TypeDef)IN_PINS)
		>> IN_SHIFT;
}

void
io_write(uint8_t val)
{
#define io_bitset(BitStatus, Port, Pin) do { \
	void (*pfnGpioWrite)(GPIO_TypeDef*, GPIO_Pin_TypeDef) = &GPIO_WriteLow; \
	if (!!(BitStatus)) pfnGpioWrite = &GPIO_WriteHigh; \
	pfnGpioWrite((Port), (Pin)); \
} while (0)

	io_bitset(val & (1 << 0), OUT1_PORT, OUT1_PIN);
	io_bitset(val & (1 << 1), OUT2_PORT, OUT2_PIN);
	io_bitset(val & (1 << 2), OUT3_PORT, OUT3_PIN);
	io_bitset(val & (1 << 3), OUT4_PORT, OUT4_PIN);
}
