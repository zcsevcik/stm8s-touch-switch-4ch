#ifndef MODBUS_H_
#define MODBUS_H_

#include "stm8s.h"

void modbus_init(void);
void modbus_rx_callback(void);
void modbus_tx_callback(void);

#endif //MODBUS_H_
