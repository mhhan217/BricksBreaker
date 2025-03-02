#include <stdio.h>
#include "raylib.h"
#include "Zidan.h"
#include <time.h>
#include <stdlib.h>


#define BRICK_WIDTH 30
#define BRICK_HEIGHT 20
#define ROWS 5

int main() {
    InitWindow(SCREEN_HEIGHT,SCREEN_WIDTH, "Bricks Random");
    SetTargetFPS(60);
    srand(time(NULL));
    
    Brick bricks[JUMLAH_BARIS + TAMBAHAN_BARIS][JUMLAH_KOLOM];
    int barisSaatIni = JUMLAH_BARIS;
    float timer = 0;
    
    InisialisasiBricks(bricks);
    
    while (!WindowShouldClose()) {
        timer += GetFrameTime();
        
        if (timer >= BATAS_WAKTU) {
            TambahBarisBricks(bricks, &barisSaatIni);
            timer = 0;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        GambarBricks(bricks);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}

Color WarnaAcak() {
    Color warna[] = {BLUE, YELLOW, GREEN, RED};
    return warna[rand() % 4];
}

void InisialisasiBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]) {
    for (int i = 0; i < JUMLAH_BARIS; i++) {
        for (int j = 0; j < JUMLAH_KOLOM; j++) {
            if (rand() % 2 == 0 ) { // 50% kemungkinan muncul
                bricks[i][j].rect = (Rectangle){j * BRICK_LEBAR, i * BRICK_TINGGI, BRICK_LEBAR, BRICK_TINGGI};
                bricks[i][j].color = WarnaAcak();
                bricks[i][j].active = true;
            } else {
                bricks[i][j].active = false;
            }
        }
    }
}

void GambarBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]) {
    for (int i = 0; i < JUMLAH_BARIS; i++) {
        for (int j = 0; j < JUMLAH_KOLOM; j++) {
            if (bricks[i][j].active) {
                DrawRectangleRec(bricks[i][j].rect, bricks[i][j].color);
            }
        }
    }
}

void TambahBarisBricks(Brick bricks[JUMLAH_BARIS + TAMBAHAN_BARIS][JUMLAH_KOLOM], int *barisSaatIni) {
    if (*barisSaatIni < JUMLAH_BARIS + TAMBAHAN_BARIS) {
        for (int j = 0; j < JUMLAH_KOLOM; j++) {
            if (rand() % 2 == 0) {
                bricks[*barisSaatIni][j].rect = (Rectangle){j * BRICK_LEBAR, *barisSaatIni * BRICK_TINGGI, BRICK_LEBAR, BRICK_TINGGI};
                bricks[*barisSaatIni][j].color = WarnaAcak();
                bricks[*barisSaatIni][j].active = true;
            } else {
                bricks[*barisSaatIni][j].active = false;
            }
        }
        (*barisSaatIni)++;
    }
}
