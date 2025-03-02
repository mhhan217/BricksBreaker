#include <stdio.h>
#include "Billy.h"
#include "Hanif.h"
#include "Hanif.h"
#include <math.h>

void inisialisasiBalok() {
    int i=0;
    while (i < BRICK_ROWS) {
        int j=0;
        while (j < BRICK_COLS){
            bricks[i][j].kotak.x = j * (BRICK_WIDTH + BRICK_PADDING) + 38;
            bricks[i][j].kotak.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 38;
            bricks[i][j].kotak.width = BRICK_WIDTH;
            bricks[i][j].kotak.height = BRICK_HEIGHT;
            bricks[i][j].on = true;
            j++;
        }
        i++; 
    }    
}

void gambarBalok() {
    int i=0;
    while (i < BRICK_ROWS) {
        int j=0;
        while (j < BRICK_COLS){
            if (bricks[i][j].on) {
                DrawRectangleRec(bricks[i][j].kotak, BLUE);
            }
            j++;
        }
        i++; 
    }
}

void bolaterkenabalok(Ball* Ball) {

    int i = 0;
    while (i < BRICK_ROWS) {
        int j = 0;
        while (j < BRICK_COLS) {
            Balok *brick = &bricks[i][j];  // Mengambil referensi brick saat ini

            if (!brick->on) {  
                j++;  
                continue;  // Jika brick sudah hancur, lewati
            }

            // Cek apakah bola berada dalam area brick
            if (Ball->Posisi.x + Ball->Radius >= brick->kotak.x && 
                Ball->Posisi.x <= brick->kotak.x + BRICK_WIDTH &&
                Ball->Posisi.y + Ball->Radius >= brick->kotak.y && 
                Ball->Posisi.y <= brick->kotak.y + BRICK_HEIGHT) {

                brick->on = false;  // Hancurkan brick
                Ball->Kecepatan.y = -Ball->Kecepatan.y;  // Pantulkan bola
                return;  // Keluar dari fungsi setelah satu brick dihancurkan
            }

            j++;
        }
        i++;
    }
}