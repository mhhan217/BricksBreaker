#include <string.h>  
#include "Faridha.h"
#include <stdlib.h>
#include <stdbool.h>

int gameState = 0;
bool isPaused = false;
int selectedButton = 0;

void InisialisasiLayarGameOver(LayarGameOver *layar) {
    strcpy(layar->pesan, "GAME OVER");  
    layar->warnaTeks = RED;
}

void RestartGame(ScreenControl *screen) {
    screen->gameState = PLAYING;
}

void KembaliKeMenu(ScreenControl *screen) {
    screen->gameState = MENU;
}

void PauseGame(ScreenControl *screen) {
    if (IsKeyPressed(KEY_P)) {
        screen->gameState = PAUSED;
    }
}

void ResumeGame(ScreenControl *screen) {
    if (IsKeyPressed(KEY_R)) {
        screen->gameState = PLAYING;
    }
}

void KeluarPermainan() {
    CloseWindow();
    exit(0);
}

void ShowGameOver() {//
    gameState = 0;
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
    const char *menuItems[] = {"Restart", "Select Level", "Menu", "Exit"};

    // Judul Game Over
    const char *judul = "GAME OVER";
    int posisiXJudul = SCREEN_WIDTH / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = SCREEN_HEIGHT / 4;
    DrawText(judul, posisiXJudul, posisiYJudul, 40, RED);

    // Posisi tombol
    int tombolLebarNormal = 200;
	int tombolLebarTerpilih = 220;
	int tombolXNormal = SCREEN_WIDTH / 2 - tombolLebarNormal / 2;
	int tombolXTerpilih = SCREEN_WIDTH / 2 - tombolLebarTerpilih / 2;
	int tombolY = SCREEN_HEIGHT / 2 - 60;

    for (int i = 0; i < 4; i++) {
        bool isSelected = (i == screen->index);
        int tombolLebar = isSelected ? 220 : 200;
        int tombolTinggi = isSelected ? 50 : 40;
		int tombolX = isSelected ? tombolXTerpilih : tombolXNormal;
        Color warna = buttonColors[i];

        DrawRectangleLines(tombolX, tombolY + (i * 50), tombolLebar, tombolTinggi, warna);
        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2, 
                 tombolY + (i * 50) + (tombolTinggi / 2 - 10), 20, warna);
    }

    EndDrawing();
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


void HapusLayarGameOver(LayarGameOver *layar) {
}

