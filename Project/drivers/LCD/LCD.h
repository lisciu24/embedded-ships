#ifndef __LCD_H
#define __LCD_H

#include "LCD_ILI9325.h"
#include "Open1768_LCD.h"
#include "asciiLib.h"
#include <stdint.h>

void LCD_initialize();
void LCD_reset_area();
void LCD_clear(uint16_t color);

void LCD_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
void LCD_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                   uint16_t color);
void LCD_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                   uint16_t color);
void LCD_draw_polygon(int n, uint16_t x[], uint16_t y[], uint16_t color);

void LCD_fill_rect(uint16_t x, uint16_t y, int w, int h, uint16_t color);

void LCD_draw_char(uint16_t x, uint16_t y, char c, uint16_t color);
void LCD_draw_str(uint16_t x, uint16_t y, char *c, uint16_t color);

void LCD_draw_board();

#endif
