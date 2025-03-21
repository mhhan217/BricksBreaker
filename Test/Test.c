#include "raylib.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Hanif.h"
#include "../Include/Billy.h"
#include "../Include/Zahwa.h"

int main() {
    // Inisialisasi jendela game
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker Game");
    SetTargetFPS(TARGET_FPS);

    // Struktur utama untuk mengontrol game
    ScreenControl screen = {PLAY, 0};
    Difficulty selectedDifficulty = EASY;
    int selectedNumber = 1;  // Misalnya, level pertama

    // Loop utama game
    while (!WindowShouldClose()) {
        // Update game logic
        updateGame(&screen, &selectedDifficulty, &selectedNumber);

        // Gambar game
        drawGame(&screen, &selectedDifficulty, &selectedNumber);
    }

    // Tutup jendela game
    CloseWindow();
    return 0;
}
