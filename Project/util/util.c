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