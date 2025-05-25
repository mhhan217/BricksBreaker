#include "../Include/Konfigurasi.h"
#include "../Include/Hanif.h"

int currentindex=0;

void DrawPauseScreen(GameState* gameState) {
    const char *menuItems[] = {"Restart", "Menu", "Exit", "Back"};

    DrawText("PAUSED", SCREEN_WIDTH / 2 - MeasureText("PAUSED", 40) / 2, 50, 40, WHITE);

    for (int i = 0; i < 4; i++) {
        Color color = (i == currentindex) ? YELLOW : GRAY;
        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2,
                 150 + (i * 50), 20, color);
    }
}

void HandlePauseInput(GameState* gameState) {
    if (IsKeyPressed(KEY_UP)) {
        currentindex = (currentindex == 0) ? 3 : currentindex - 1;
    }
    else if (IsKeyPressed(KEY_DOWN)) {
        currentindex = (currentindex == 3) ? 0 : currentindex + 1;
    }
    else if (IsKeyPressed(KEY_ENTER)) {
        switch (currentindex) {
            case 0:  *gameState = RESTART ; break; // Restart
            case 1: *gameState = MENU; break; //menu
            case 2: CloseWindow();// keluar
            case 3: *gameState = PLAY; break; // back
        }
    }
}