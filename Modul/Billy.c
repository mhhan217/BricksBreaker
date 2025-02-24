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

//void checkBenturanBalok() {
//
//}