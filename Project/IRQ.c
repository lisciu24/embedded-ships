#include "LPC17xx.h"
#include "drivers/TP/TP.h"

void EINT3_IRQHandler() {
	TP_IRQ_callback();
	LPC_GPIOINT->IO0IntClr |= 1 << 19;
	handle_touch(LCDBlue);
}

