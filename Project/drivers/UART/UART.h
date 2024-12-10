#ifndef __UART_H
#define __UART_H

#include "Driver_USART.h"

extern ARM_DRIVER_USART Driver_USART0;
ARM_DRIVER_USART *USARTdrv = &Driver_USART0;

void UART_initialize();
void UART_send(char *msg);

#endif