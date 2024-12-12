#include "LCD.h"

void LCD_initialize() { init_ILI9325(); }

void LCD_reset_area() {
  lcdWriteReg(HADRPOS_RAM_START, 0);
  lcdWriteReg(HADRPOS_RAM_END, LCD_MAX_X);
  lcdWriteReg(VADRPOS_RAM_START, 0);
  lcdWriteReg(VADRPOS_RAM_END, LCD_MAX_Y);
}

void LCD_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
  lcdWriteReg(ADRX_RAM, x);
  lcdWriteReg(ADRY_RAM, y);
  lcdWriteReg(DATA_RAM, color);
}

void LCD_clear(uint16_t color) {
  LCD_reset_area();
  lcdWriteReg(ADRX_RAM, 0);
  lcdWriteReg(ADRY_RAM, 0);
  lcdWriteIndex(DATA_RAM);
  for (int i = 0; i < LCD_MAX_X * LCD_MAX_Y; i++) {
    lcdWriteData(color);
  }
}

void LCD_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                   uint16_t color) {
  int d, dx, dy, ai, bi, xi, yi;
  int x = x1, y = y1;

  if (x1 < x2) {
    xi = 1;
    dx = x2 - x1;
  } else {
    xi = -1;
    dx = x1 - x2;
  }

  if (y1 < y2) {
    yi = 1;
    dy = y2 - y1;
  } else {
    yi = -1;
    dy = y1 - y2;
  }

  LCD_draw_pixel(x, y, color);

  if (dx > dy) {
    ai = (dy - dx) * 2;
    bi = dy * 2;
    d = bi - dx;
    while (x != x2) {
      if (d >= 0) {
        x += xi;
        y += yi;
        d += ai;
      } else {
        d += bi;
        x += xi;
      }
      LCD_draw_pixel(x, y, color);
    }
  } else {
    ai = (dx - dy) * 2;
    bi = dx * 2;
    d = bi - dy;
    while (y != y2) {
      if (d >= 0) {
        x += xi;
        y += yi;
        d += ai;
      } else {
        d += bi;
        y += yi;
      }
      LCD_draw_pixel(x, y, color);
    }
  }
}

void LCD_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                   uint16_t color) {
  LCD_draw_line(x, y, x + w, y, color);
  LCD_draw_line(x + w, y, x + w, y + h, color);
  LCD_draw_line(x + w, y + h, x, y + h, color);
  LCD_draw_line(x, y + h, x, y, color);
}

void LCD_fill_rect(uint16_t x, uint16_t y, int w, int h, uint16_t color) {
  lcdWriteReg(ADRX_RAM, x);
  lcdWriteReg(ADRY_RAM, y);
  lcdWriteReg(HADRPOS_RAM_START, x);
  lcdWriteReg(HADRPOS_RAM_END, x + w);
  lcdWriteReg(VADRPOS_RAM_START, y);
  lcdWriteReg(VADRPOS_RAM_END, y + h);
  lcdWriteIndex(DATA_RAM);
  for (int i = 0; i < (w + 1) * (h + 1); i++) {
    lcdWriteData(color);
  }
  LCD_reset_area();
}

void LCD_draw_polygon(int n, uint16_t x[], uint16_t y[], uint16_t color) {
  int i = 0;
  for (i = 1; i < n; i++) {
    LCD_draw_line(x[i - 1], y[i - 1], x[i], y[i], color);
  }
  LCD_draw_line(x[n - 1], y[n - 1], x[0], y[0], color);
}

void LCD_draw_char(uint16_t x, uint16_t y, char c, uint16_t color) {
  uint8_t character[16];
  GetASCIICode(ASCII_8X16_MS_Gothic, character, c);
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 8; j++) {
      if (character[i] & (0x80 >> j))
        LCD_draw_pixel(x + j, y + i, color);
    }
  }
}

void LCD_draw_str(uint16_t x, uint16_t y, char *c, uint16_t color) {
  while (*c) {
    LCD_draw_char(x, y, *c, color);
    c++;
    x += 8;
  }
}