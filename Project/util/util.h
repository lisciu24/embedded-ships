#ifndef __UTIL_H
#define __UTIL_H

void UTIL_calibrate_TP();

void UTIL_get_XY(int *x, int *y);

void UTIL_map_XY_to_LCD(int *x, int *y);
int UTIL_map(int x, int in_min, int in_max, int out_min, int out_max);

/// TODO: blocking delay

#endif
