#ifndef ZIDAN_H
#define ZIDAN_H

#include "raylib.h"
#include "Konfigurasi.h"


typedef struct {
    Rectangle rect; 
    Color warna;    
    bool active;    
} Blok;


typedef struct {
    Blok *blok;    
    int jumlah;     
} blokPengatur; 

void initblokPengatur(blokPengatur *pengatur);
void menambahBlok(blokPengatur *pengatur);
void menghapusBlok1();

#endif
