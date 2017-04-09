#include "iic.h"

void
iic_init(void)
{
	I2C_DeInit();
	GPIO_Init(GPIOB, GPIO_PIN_5|GPIO_PIN_4, GPIO_MODE_OUT_OD_HIZ_SLOW);
}

void
iic_callback(void)
{
}
