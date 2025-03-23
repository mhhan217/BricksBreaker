#include "../Include/konfigurasi.h"
#include "../Include/Hanif.h"
#include "../Include/Billy.h"
#include "../Include/Zahwa.h"
#include "../Include/Faridha.h"
#include "raylib.h"

void HandleMenu(ScreenControl *screen) {
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index + 1) % 4; // 4 opsi: PLAY, INFO, SETTINGS, EXIT
    }
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index - 1 + 4) % 4;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        switch (screen->index) {
            case 0: screen->gameState = PLAY; break;       // Mulai game
            case 1: screen->gameState = INFO; break;       // Menu info
            case 2: screen->gameState = SETTINGS; break;   // Menu settings
            case 3: screen->gameState = EXIT; break;       // Keluar game
        }
    }
}

void HandleGameOverInput(ScreenControl *screen) {
    // Navigasi menu
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index == 0) ? 3 : screen->index - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index == 3) ? 0 : screen->index + 1;
    }

    // Pilihan menu berdasarkan index
    if (IsKeyPressed(KEY_ENTER)) {
        switch (screen->index) {
            case 0:
                screen->gameState = PLAY;  // Restart game
            break;
            case 1:
                screen->gameState = LEVEL_SELECTION;  // Kembali ke pemilihan level
            break;
            case 2:
                screen->gameState = MENU;  // Kembali ke menu utama
            break;
            case 3:
                screen->gameState = EXIT;  // Keluar dari game
            break;
        }
    }
}

void HandlePauseInput(ScreenControl *screen) {
    // Navigasi menu
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index == 0) ? 4 : screen->index - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index == 4) ? 0 : screen->index + 1;
    }

    // Pilihan menu berdasarkan index
    if (IsKeyPressed(KEY_ENTER)) {
        switch (screen->index) {
            case 0:
                screen->gameState = SETTINGS;  // Masuk ke pengaturan
            break;
            case 1:
                screen->gameState = PLAY;  // Restart game
            break;
            case 2:
                screen->gameState = MENU;  // Kembali ke menu utama
            break;
            case 3:
                screen->gameState = EXIT;  // Keluar dari game
            break;
            case 4:
                screen->gameState = LEVEL_SELECTION;  // Pilih level
            break;
        }
    }
}

void drawGame(ScreenControl* screen, Difficulty* selectDifficult, int* selectNumber) {
    BeginDrawing();
    ClearBackground(BLACK);

    // Gambar objek game
    drawBall(&ball);
    DrawPaddle(paddle);
    gambarBalok(); // Menampilkan balok

    EndDrawing();
}





