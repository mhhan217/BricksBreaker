#include <string.h>  
#include "../Include/Konfigurasi.h"
#include <stdlib.h>
#include <stdbool.h>

void displayGameOver(ScreenControl *screen) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        // Teks "GAME OVER" dengan warna MY_DARK_PINK untuk semua huruf
        DrawText("G", 290, 50, 40, MY_DARK_PINK);
        DrawText("A", 320, 50, 40, MY_DARK_PINK);
        DrawText("M", 350, 50, 40, MY_DARK_PINK);
        DrawText("E", 380, 50, 40, MY_DARK_PINK);
        DrawText(" ", 410, 50, 40, MY_DARK_PINK);
        DrawText("O", 440, 50, 40, MY_DARK_PINK);
        DrawText("V", 470, 50, 40, MY_DARK_PINK);
        DrawText("E", 500, 50, 40, MY_DARK_PINK);
        DrawText("R", 530, 50, 40, MY_DARK_PINK);

        // Menu Opsi
        const char *menuOptions[] = { "Restart", "Select Level", "Menu", "Exit" };
        Color highlightColors[] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW };
        int menuCount = 4;

        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
            screen->index = (screen->index + 1) % menuCount;
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
            screen->index = (screen->index - 1 + menuCount) % menuCount;

        for (int i = 0; i < menuCount; i++) {
            Color textColor = (i == screen->index) ? highlightColors[i] : WHITE;
            DrawText(menuOptions[i], 350, 150 + (i * 60), 30, textColor);
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            switch (screen->index) {
                case 0: screen->gameState = PLAY; break;
                case 1: screen->gameState = LEVEL_SELECTION; break;
                case 2: screen->gameState = MENU; break;
                case 3: screen->gameState = EXIT; break;
            }
        }

        EndDrawing();
    }
}



