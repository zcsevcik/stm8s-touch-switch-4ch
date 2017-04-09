#include "modbus.h"

void
modbus_init(void)
{
	UART1_DeInit();
	GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_SLOW);
	GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_SLOW);
	GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);
}

void
modbus_rx_callback(void)
{
}

void
modbus_tx_callback(void)
{
}
