#include "raylib.h"
#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"

int main() {
    // Inisialisasi window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 15.0f);

    // Inisialisasi bola
    Ball bola;
    InitBall(&bola,(Vector2){0,-20},&paddle);

    while (!WindowShouldClose()) {
        UpdateBall(&bola,&paddle,(Vector2){0,-20});
        UpdatePaddle(&paddle);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBall(bola);
        DrawPaddle(paddle);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
