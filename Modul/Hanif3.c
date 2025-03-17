#include "Konfigurasi.h"
#include "Hanif.h"

void DrawPauseScreen(ScreenControl *screen) {
    BeginDrawing();
    ClearBackground(BLACK);

    // Judul "PAUSED"
    DrawText("PAUSED", SCREEN_WIDTH / 2 - MeasureText("PAUSED", 40) / 2, 50, 40, WHITE);

    // Warna untuk highlight menu yang dipilih
    Color colors[6] = {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
    colors[screen->index] = YELLOW; // Highlight menu yang dipilih

    // Array teks menu
    const char *menuItems[] = {"Settings", "Restart", "Select Level", "Menu", "Exit", "Back"};

    // Menampilkan menu vertikal
    for (int i = 0; i < 6; i++) {
        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2,
                 150 + (i * 50), 20, colors[i]);
    }

    EndDrawing();
}
void HandlePauseInput(ScreenControl *screen) {
    // Navigasi menu pause
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index == 0) ? 5 : screen->index - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index == 5) ? 0 : screen->index + 1;
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
                screen->gameState = LEVEL_SELECTION;  // Pilih level
            break;
            case 3:
                screen->gameState = MENU;  // Kembali ke menu utama
            break;
            case 4:
                CloseWindow();  // Keluar dari game
            break;
            case 5:
                screen->gameState = PLAY;  // Kembali ke permainan
            break;
        }
    }
}


