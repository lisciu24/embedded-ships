#include "TP.h"

void TP_initialize() { touchpanelInit(); }
void TP_set_bounds(int min_x, int max_x, int min_y, int max_y) {
  TP_config.MIN_READ_X = min_x;
  TP_config.MAX_READ_X = max_x;
  TP_config.MIN_READ_Y = min_y;
  TP_config.MAX_READ_Y = max_y;
}

int TP_read_X() { return touchpanelReadX(); }
int TP_read_Y() { return touchpanelReadY(); }
void TP_read_XY(int *x, int *y) { touchpanelGetXY(x, y); }