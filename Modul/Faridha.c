#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Faridha.h"
#include "Konfigurasi.h"
#include "Hanif.h"

#define TOTAL_BUTTONS 4

GameState*  gameState;
bool isPaused = false;
int selectedButton = 0;

void InisialisasiLayarGameOver(LayarGameOver *layar) {
    strcpy(layar->pesan, "GAME OVER");  
    layar->warnaTeks = RED;
}

void ShowGameOver() {
    gameState = GAME_OVER;
}

void PauseGame() {
    if (IsKeyPressed(KEY_P)) {
        gameState = PAUSE;
    }
}

void ResumeGame() {
    if (IsKeyPressed(KEY_R)) {
        gameState = PLAY;
    }
}

void DrawGameOverScreen(ScreenControl *screen) {
    BeginDrawing();
    ClearBackground(BLACK);

    Color warnaHuruf[] = {PINK, BLUE, GREEN, YELLOW};
    
    const char *judulGame = "Bricks Breaker Game";
    int posisiXJudulGame = SCREEN_WIDTH / 2 - MeasureText(judulGame, 30) / 2;
    int posisiYJudulGame = SCREEN_HEIGHT / 6;
    int jarakHuruf = 5;
    
    for (int i = 0; i < strlen(judulGame); i++) {
        DrawText(TextFormat("%c", judulGame[i]), posisiXJudulGame, posisiYJudulGame, 30, warnaHuruf[i % (sizeof(warnaHuruf) / sizeof(warnaHuruf[0]))]);
        posisiXJudulGame += MeasureText(TextFormat("%c", judulGame[i]), 30) + jarakHuruf;
    }

    // Warna tombol
    Color buttonColors[] = {BLUE, GREEN, YELLOW, RED}; 
    const char *menuItems[TOTAL_BUTTONS] = {"Restart", "Select Level", "Menu", "Exit"};

    // Judul Game Over
    const char *judul = "GAME OVER";
    int posisiXJudul = SCREEN_WIDTH / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = SCREEN_HEIGHT / 4;
    DrawText(judul, posisiXJudul, posisiYJudul, 40, RED);

    // Posisi tombol
    int tombolLebar = 200;
    int tombolLebarTerpilih = 220;
    int tombolXNormal = SCREEN_WIDTH / 2 - tombolLebar / 2;
    int tombolXTerpilih = SCREEN_WIDTH / 2 - tombolLebarTerpilih / 2;
    int tombolY = SCREEN_HEIGHT / 2 - 60;

    for (int i = 0; i < TOTAL_BUTTONS; i++) {
        bool isSelected = (i == screen->index);
        int tombolX = isSelected ? tombolXTerpilih : tombolXNormal;
        Color warna = buttonColors[i];

        DrawRectangleLines(tombolX, tombolY + (i * 50), isSelected ? 220 : 200, isSelected ? 50 : 40, warna);
        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2, 
                 tombolY + (i * 50) + 15, 20, warna);
    }

    EndDrawing();
}

void HandleGameOverInput(ScreenControl *screen) {
    DrawGameOverScreen(screen);
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index == 0) ? TOTAL_BUTTONS - 1 : screen->index - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index == TOTAL_BUTTONS - 1) ? 0 : screen->index + 1;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (screen->index) {
            case 0:
                gameState = PLAY;
                break;
            case 1:
                gameState = LEVEL_SELECTION;
                break;
            case 2:
                gameState = MENU;
                break;
            case 3:
                CloseWindow();
                exit(0);
                break;
        }
    }
}

void HapusLayarGameOver(LayarGameOver *layar) {
}
