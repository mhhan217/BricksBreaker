#include "raylib.h"
#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"

int main() {
    // Inisialisasi window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    // Inisialisasi bola
    Ball bola;
    InitBall(&bola, (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

    while (!WindowShouldClose()) {
        UpdateBall(&bola);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBall(bola);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
