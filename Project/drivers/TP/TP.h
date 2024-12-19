#ifndef __TP_H
#define __TP_H

#include "TP_Open1768.h"

static struct {
  int MIN_READ_X;
  int MAX_READ_X;

  int MIN_READ_Y;
  int MAX_READ_Y;
  int read;
} TP_config;


void TP_IRQ_callback();
void TP_IRQ_initialize();

/// TODO: write interrupt with average read
/// TODO: flag read ready

void TP_initialize();
void TP_set_bounds(int min_x, int max_x, int min_y, int max_y);

int TP_read_X();
int TP_read_Y();
void TP_read_XY(int *x, int *y);
void TP_touched(int* x, int* y);
void handle_touch(uint16_t color);
void draw_ship(uint16_t x, uint16_t y, uint16_t color);
#endif
