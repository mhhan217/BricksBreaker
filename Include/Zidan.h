#ifndef ZIDAN_H
#define ZIDAN_H

#include "Konfigurasi.h"

typedef struct {
    Rectangle rect;
    Color color;
    bool active;
} Brick;

void InisialisasiBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]);
void GambarBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]);

#endif
