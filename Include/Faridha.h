#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

typedef struct {
    char pesan[20];  
    int lebarLayar;
    int tinggiLayar;
    Color warnaTeks;
} LayarGameOver;

void InisialisasiLayarGameOver(LayarGameOver *layar);
void GambarLayarGameOver(LayarGameOver layar);
void HapusLayarGameOver(LayarGameOver *layar);

#endif
