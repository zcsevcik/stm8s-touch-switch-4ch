#include "iic.h"

void
iic_init(void)
{
	I2C_DeInit();
	I2C_Init(100000, 0x30, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, 2);
	I2C_ITConfig((I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF), ENABLE);
}

void
iic_callback(void)
{
	/* Read SR2 register to get I2C error */
	if ((I2C->SR2) != 0)
	{
		/* Clears SR2 register */
		I2C->SR2 = 0;
	}

	switch (I2C_GetLastEvent())
	{
	/******* Slave transmitter ******/
		/* check on EV1 */
		case I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED:
			break;

		/* check on EV3 */
		case I2C_EVENT_SLAVE_BYTE_TRANSMITTING:
			/* Transmit data */
			I2C_SendData(0x00);
			break;

	/******* Slave receiver **********/
		/* check on EV1*/
		case I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED:
			break;

		/* Check on EV2*/
		case I2C_EVENT_SLAVE_BYTE_RECEIVED:
			(void)I2C_ReceiveData();
			break;

		/* Check on EV4 */
		case (I2C_EVENT_SLAVE_STOP_DETECTED):
			/* write to CR2 to clear STOPF flag */
			I2C->CR2 |= I2C_CR2_ACK;
			break;

		default:
			break;
	}

}
