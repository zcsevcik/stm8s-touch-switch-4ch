#include "stm8s.h"
#include "io.h"

main()
{
	// Sets the SystemClock
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV4); // fMASTER := 4 MHz
	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV4); // fCPU = 1 MHz
	CLK_SWIMConfig(CLK_SWIMDIVIDER_2);
	CLK_PeripheralClockConfig(CLK_PERIPHERAL_I2C, ENABLE);
	CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, ENABLE);
	
	// Sets the I/O ports
	io_init();

	// Enable interrupts
	rim();

	while (1)
	{
	}
}