#include <stdio.h>
#include "raylib.h"
#include "Zidan.h"
#include <time.h>
#include <stdlib.h>


#define BRICK_WIDTH 50
#define BRICK_HEIGHT 20
#define ROWS 5

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "Bricks Random");
    SetTargetFPS(60);
    srand(time(NULL));
    
    Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM];
    InisialisasiBricks(bricks);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        GambarBricks(bricks);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}


void InisialisasiBricks(Brick bricks[JUMLAH_BARIS][JUMLAH_KOLOM]) {
    for (int i = 0; i < JUMLAH_BARIS; i++) {
        for (int j = 0; j < JUMLAH_KOLOM; j++) {
            if (rand() % 2 == 0) { // 50% kemungkinan muncul
                bricks[i][j].rect = (Rectangle){j * BRICK_LEBAR, i * BRICK_TINGGI, BRICK_LEBAR, BRICK_TINGGI};
                bricks[i][j].color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};
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

