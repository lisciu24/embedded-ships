#include "util.h"
#include "LCD.h"
#include "TP.h"

void UTIL_calibrate_TP() {
  LCD_clear(LCDWhite);
  LCD_draw_line(5, 5, 10, 10, LCDBlack);
  LCD_draw_line(5, 10, 10, 5, LCDBlack);

  LCD_draw_line(5, LCD_MAX_Y - 5, 10, LCD_MAX_Y - 10, LCDBlack);
  LCD_draw_line(5, LCD_MAX_Y - 10, 10, LCD_MAX_Y - 5, LCDBlack);

  LCD_draw_line(LCD_MAX_X - 5, 5, LCD_MAX_X - 10, 10, LCDBlack);
  LCD_draw_line(LCD_MAX_X - 5, 10, LCD_MAX_X - 10, 5, LCDBlack);

  LCD_draw_line(LCD_MAX_X - 5, LCD_MAX_Y - 5, LCD_MAX_X - 10, LCD_MAX_Y - 10,
                LCDBlack);
  LCD_draw_line(LCD_MAX_X - 5, LCD_MAX_Y - 10, LCD_MAX_X - 10, LCD_MAX_Y - 5,
                LCDBlack);

  /// TODO: read TP after every 'X'
  /// TODO: set TP bounds
  // TP_set_bounds(int min_x, int max_x, int min_y, int max_y);
}

void UTIL_get_XY(int *x, int *y) {
  TP_read_XY(x, y);
  UTIL_map_XY_to_LCD(x, y);
}

void UTIL_map_XY_to_LCD(int *x, int *y) {
  *x = UTIL_map(*x, TP_config.MIN_READ_X, TP_config.MAX_READ_X, 0, LCD_MAX_X);
  *y = UTIL_map(*y, TP_config.MIN_READ_Y, TP_config.MAX_READ_Y, 0, LCD_MAX_Y);
}

int UTIL_map(int value, int in_min, int in_max, int out_min, int out_max) {
  return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}