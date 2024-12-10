#include "TP.h"

int TP_get_X() { return touchpanelReadX(); }
int TP_get_Y() { return touchpanelReadY(); }
void TP_get_XY(int *x, int *y) { touchpanelGetXY(x, y); }