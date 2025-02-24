#include "zahwa.h"
#include "konfigurasi.h"
#include "raylib.h"

int main() {
    // Inisialisasi jendela permainan
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "Bricks Breaker");

    // Inisialisasi paddle dan bola
    Paddle paddle;
    
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 5.0f);

    SetTargetFPS(60); // Batasi FPS ke 60

    // Loop utama permainan
    while (!WindowShouldClose()) {
        // Update paddle dan bola
        UpdatePaddle(&paddle);

        // Mulai menggambar
        BeginDrawing();
        ClearBackground(BLACK);

        // Gambar paddle dan bola
        DrawPaddle(paddle);

        DrawText("Press ESC to exit", 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow(); // Menutup jendela permainan
    return 0;
}
