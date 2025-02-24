
#include "Konfigurasi.h"
#include "Zidan.h"

#define BRICK_WIDTH 50
#define BRICK_HEIGHT 20
#define ROWS 5

typedef struct {
    int r, g, b, a;
} warna;

typedef struct {
    int x, y, width, height;
    warna warna;
    int active;
} blok;

typedef struct {
    blok *blok;
    int jumlah;
} blokPengatur;

void initblokPengatur(blokPengatur *pengatur) {
    pengatur->blok = NULL;
    pengatur->jumlah = 0;
    srand(time(NULL));
}
void menghapusBlok1(){
}
