#include <stdio.h>
#include "raylib.h"
#include "Billy.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(60);

    //Ball ball = {{400, 300}, {4, -4}, 10, true};
    inisialisasiBalok();

    while (!WindowShouldClose()) {
        // Cek tabrakan
        //checkBenturanBalok(&ball);

        // Gambar game //
        BeginDrawing();
        ClearBackground(BLACK);
        gambarBalok();
        // DrawCircleV(ball.position, ball.radius, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void inisialisasiBalok(){
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

//void checkBenturanBalok() {

//}