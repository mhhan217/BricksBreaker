#ifndef BILLY_H
#define BILLY_H
#include "Konfigurasi.h"

#define BRICK_ROWS 10
#define BRICK_COLS 9
#define BRICK_WIDTH 75
#define BRICK_HEIGHT 30
#define BRICK_PADDING 5

typedef struct
{
    Rectangle Rectangle;
    bool on;
} Balok;

Balok bricks[BRICK_ROWS][BRICK_COLS];

void inisialisasiBalok() {
    int i=0;
    while (i < BRICK_ROWS) {
        int j=0;
        while (j < BRICK_COLS){
            bricks[i][j].Rectangle.x = j * (BRICK_WIDTH + BRICK_PADDING) + 38;
            bricks[i][j].Rectangle.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 38;
            bricks[i][j].Rectangle.width = BRICK_WIDTH;
            bricks[i][j].Rectangle.height = BRICK_HEIGHT;
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
                DrawRectangleRec(bricks[i][j].Rectangle, BLUE);
            }
            j++;
        }
        i++; 
    }
}

#endif //BILLY_H
