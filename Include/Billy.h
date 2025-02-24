#ifndef BILLY_H
#define BILLY_H
#include "Konfigurasi.h"

#define BRICK_ROWS 10
#define BRICK_COLS 9
#define BRICK_WIDTH 75
#define BRICK_HEIGHT 30
#define BRICK_PADDING 5

typedef struct
{
    Rectangle Rectangle;
    bool on;
} Balok;

Balok bricks[BRICK_ROWS][BRICK_COLS];

void inisialisasiBalok();
void gambarBalok();
void checkBenturanBalok();

#endif //BILLY_H
