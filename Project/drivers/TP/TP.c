#include "TP.h"
#include "../UART/UART.h"
#include "../LCD/LCD.h"


void TP_initialize() { 
	touchpanelInit(); 
	TP_config.read = 0;
	TP_IRQ_initialize();
}

void TP_IRQ_callback(){
	int x, y;
	TP_read_XY(&x, &y);
	char buff[128];
	sprintf(buff, "x: %d\ty: %d\n\r", x, y);
	UART_send(buff);
}

void TP_IRQ_initialize() {
	LPC_GPIOINT->IO0IntEnF |= 1 << 19;
	NVIC_EnableIRQ(EINT3_IRQn);
}

void TP_set_bounds(int min_x, int max_x, int min_y, int max_y) {
  TP_config.MIN_READ_X = min_x;
  TP_config.MAX_READ_X = max_x;
  TP_config.MIN_READ_Y = min_y;
  TP_config.MAX_READ_Y = max_y;
}

int TP_read_X() { return touchpanelReadX(); }
int TP_read_Y() { return touchpanelReadY(); }
void TP_read_XY(int *x, int *y) { touchpanelGetXY(x, y); }

void TP_touched(int* x, int* y){
	int avg_x = 0;
	int avg_y 0;
	for(int i=0; i<10; i++){
		int temp_x;
		int temp_y;
		TP_read_XY(&temp_x, &temp_y){
			avg_x += temp_x;
			avg_y += temp_y;
		}
	}
	avg_x /= 10;
	avg_y /= 10;
	*x = avg_x;
	*y = avg_y;
}

void handle_touch(uint16_t color){
	int x,y;
	TP_touched(&x, &y);
	x = x/10*10;
	y = y/10*10;
	draw_ship(x, y, color);
}

void draw_ship(uint16_t x, uint16_t y, uint16_t color){
	LCD_fill_rect(x, y, LCD_MAX_X/10, LCD_MAX_X/10, color)
}
