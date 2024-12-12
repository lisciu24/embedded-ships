#include "UART.h"
#include <string.h>

#define RX_BUFFER_SIZE 128

char rx_buffer[RX_BUFFER_SIZE];
volatile int rx_flag = 0;



void UART_receive() {
  while (USARTdrv->GetStatus().rx_busy) {
    continue;
  }

  USARTdrv->Receive(rx_buffer, RX_BUFFER_SIZE);

  while (!rx_flag) {
    continue;
  }

  rx_flag = 0;
}

//for interupts
//USARTdrv->Initialize(UART_callback);
void UART_callback(uint32_t event) {
  if (event & ARM_USART_EVENT_RECEIVE_COMPLETE) {
    rx_flag = 1;
  }
}

void UART_receive_example() {
  UART_receive();

  rx_buffer[strlen(rx_buffer)] = '\0';
  UART_send(rx_buffer);
}


void UART_initialize() {
  /* Initialize the USART driver */
  USARTdrv->Initialize(NULL);
  /* Power up the USART peripheral */
  USARTdrv->PowerControl(ARM_POWER_FULL);
  /* Configure the USART to 4800 Bits/sec */
  USARTdrv->Control(ARM_USART_MODE_ASYNCHRONOUS | ARM_USART_DATA_BITS_8 |
                        ARM_USART_PARITY_NONE | ARM_USART_STOP_BITS_1 |
                        ARM_USART_FLOW_CONTROL_NONE,
                    4800);

  /* Enable Receiver and Transmitter lines */
  USARTdrv->Control(ARM_USART_CONTROL_TX, 1);
  USARTdrv->Control(ARM_USART_CONTROL_RX, 1);
}

void UART_send(char *msg) {
  int count = strlen(msg);
  while (USARTdrv->GetStatus().tx_busy) {
    continue;
  }
  USARTdrv->Send(msg, count);
}
