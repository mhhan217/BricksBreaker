#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Include/Faridha.h"
#include "../Include/Chinta.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Hanif.h"

#define TOTAL_BUTTONS 4

GameState*  gameState;
bool isPaused = false;
int selectedButton = 0;

void InisialisasiLayarGameOver(LayarGameOver *layar) {
    strcpy(layar->pesan, "GAME OVER");  
    layar->warnaTeks = RED;
}

void ShowGameOver() {
    *gameState = GAME_OVER;
}

void PauseGame() {
    if (IsKeyPressed(KEY_P)) {
        *gameState = PAUSE;
    }
}

void ResumeGame() {
    if (IsKeyPressed(KEY_R)) {
        *gameState = PLAY;
    }
}

void DrawGameOverScreen(ScreenControl sc) {
    const char *menuItems[] = {"Restart", "Select Level", "Menu", "Exit"};
    Color textColors[] = {PINK, BLUE,GREEN, YELLOW};

        DrawText("B", 120, 50, 30, MY_DARK_PINK);
        DrawText("r", 140, 50, 30, MY_BLUE);
        DrawText("i", 160, 50, 30, MY_GREEN);
        DrawText("c", 180, 50, 30, MY_YELLOW);
        DrawText("k", 200, 50, 30, MY_DARK_PINK);
        DrawText("s", 220, 50, 30, MY_BLUE);
        DrawText(" ", 240, 50, 30, MY_GREEN);
        DrawText("B", 260, 50, 30, MY_YELLOW);
        DrawText("r", 280, 50, 30, MY_DARK_PINK);
        DrawText("e", 300, 50, 30, MY_BLUE);
        DrawText("a", 320, 50, 30, MY_GREEN);
        DrawText("k", 340, 50, 30, MY_YELLOW);
        DrawText("e", 360, 50, 30, MY_DARK_PINK);
        DrawText("r", 380, 50, 30, MY_BLUE);
        DrawText(" ", 400, 50, 30, MY_GREEN);
        DrawText("G", 420, 50, 30, MY_YELLOW);
        DrawText("a", 440, 50, 30, MY_DARK_PINK);
        DrawText("m", 460, 50, 30, MY_BLUE);
        DrawText("e", 480, 50, 30, MY_GREEN);
    DrawText("GAME OVER", SCREEN_WIDTH / 2 - MeasureText("GAME OVER", 40) / 2, 130, 40, RED);

    for (int i = 0; i < 4; i++) {
        int y = 200 + i * 50;

        Color color = (i == sc.index) ? textColors[i] : WHITE;

        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2, y, 20, color);
    }
}



void HandleGameOverInput(GameState *gameState, ScreenControl *sc) {
    if (IsKeyPressed(KEY_UP)) {
        sc->index = (sc->index == 0) ? 3 : sc->index - 1;
    }
    else if (IsKeyPressed(KEY_DOWN)) {
        sc->index = (sc->index == 3) ? 0 : sc->index + 1;
    }
    else if (IsKeyPressed(KEY_ENTER)) {
        switch (sc->index) {
            case 0: *gameState = RESTART; break;         // Restart
            case 1: *gameState = LEVEL_SELECTION; break;     // Select Level
            case 2: *gameState = MENU; break;             // Menu
            case 3: CloseWindow(); break;                 // Exit
        }
    }
}



void HapusLayarGameOver(LayarGameOver *layar) {
}
