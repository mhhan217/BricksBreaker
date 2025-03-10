#ifndef ZIDAN_H
#define ZIDAN_H

#include "Konfigurasi.h"

#define TAMBAHAN_BARIS 2
#define BATAS_WAKTU 10

typedef struct {
    Rectangle rect;
    Color color;
    bool active;
} Brick;




void InisialisasiBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]);
void GambarBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]);
void TambahBarisBricks(Brick bricks[JUMLAH_BARIS + TAMBAHAN_BARIS][JUMLAH_KOLOM], int *barisSaatIni);

#endif
