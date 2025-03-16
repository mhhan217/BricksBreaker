#include "../Include/Zahwa.h"
#include "raylib.h"
#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    // Inisialisasi Paddle
    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 5.0f);

    // Inisialisasi Bola
    Ball bola;
    InitBall(&bola, (Vector2){3, -5}, &paddle);

    // Inisialisasi Lives
    Lives lives;
    InitLives(&lives);

    while (!WindowShouldClose()) {
        // Update paddle dan bola
        UpdatePaddle(&paddle);
        UpdateBall(&bola, &paddle, (Vector2){3, -5});

        // Cek jika bola jatuh
        CekBolaJatuh(&lives, &bola);

        BeginDrawing();
        ClearBackground(BLACK);

        // Gambar nyawa (lives)
        DrawLives(&lives);

        // Gambar bola dan paddle
        DrawBall(bola);
        DrawPaddle(paddle);

        // Jika nyawa habis, tampilkan pesan game over
        if (lives.jumlah_nyawa <= 0) {
            DrawText("GAME OVER!", SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, 20, RED);
        }

        EndDrawing();
    }

    unloadLives(&lives);
    CloseWindow();
    
    return 0;
}