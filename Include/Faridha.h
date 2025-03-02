#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

extern int gameState;

typedef struct {
    char pesan[20];  
    int lebarLayar;
    int tinggiLayar;
    Color warnaTeks;
} LayarGameOver;

void InisialisasiLayarGameOver(LayarGameOver *layar);
void GambarLayarGameOver(LayarGameOver layar);
void GambarLayarScore();
void HapusLayarGameOver(LayarGameOver *layar);
int CekKlikTombol(int x, int y, int lebar, int tinggi);

#endif
