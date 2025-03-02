#ifndef ZIDAN_H
#define ZIDAN_H

#include "Konfigurasi.h"

#define JUMLAH_BARIS 15
#define JUMLAH_KOLOM 10

#define BRICK_LEBAR 50
#define BRICK_TINGGI 20

#define BRICK_PADDING 5
#define POSISI_TENGAH_X ((SCREEN_HEIGHT - (JUMLAH_KOLOM * (BRICK_LEBAR + BRICK_PADDING) - BRICK_PADDING)) / 2)
#define POSISI_ATAS_Y 100 

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
