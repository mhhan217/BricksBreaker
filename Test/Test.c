#include "raylib.h"
#include "Hanif.h"
#include "Konfigurasi.h"
#include "Billy.c"
#include "Hanif.c"

int main() {
    // Inisialisasi window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    // Inisialisasi bola
    Ball bola;
    InitBall(&bola, (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

    inisialisasiBalok();

    while (!WindowShouldClose()) {
        UpdateBall(&bola);
        bolaterkenabalok(&bola); 
        BeginDrawing();
        gambarBalok();
        ClearBackground(BLACK);
        DrawBall(bola);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
