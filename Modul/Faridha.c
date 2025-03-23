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

void DrawGameOverScreen(ScreenControl *screen) {
    BeginDrawing();
    ClearBackground(BLACK);

    // Warna teks judul
    Color warnaHuruf[] = {PINK, BLUE, GREEN, YELLOW};
    const char *judulGame = "Bricks Breaker Game";
    int posisiXJudulGame = SCREEN_WIDTH / 2 - MeasureText(judulGame, 30) / 2;
    int posisiYJudulGame = SCREEN_HEIGHT / 6;
    int jarakHuruf = 5;

    // Menampilkan judul game dengan warna berbeda per huruf
    for (int i = 0; i < strlen(judulGame); i++) {
        DrawText(TextFormat("%c", judulGame[i]), posisiXJudulGame, posisiYJudulGame, 30, warnaHuruf[i % (sizeof(warnaHuruf) / sizeof(warnaHuruf[0]))]);
        posisiXJudulGame += MeasureText(TextFormat("%c", judulGame[i]), 30) + jarakHuruf;
    }

    // Judul "GAME OVER"
    const char *judul = "GAME OVER";
    int posisiXJudul = SCREEN_WIDTH / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = SCREEN_HEIGHT / 4;
    DrawText(judul, posisiXJudul, posisiYJudul, 40, RED);

    // Menu tombol
    const char *menuItems[TOTAL_BUTTONS] = {"Restart", "Select Level", "Menu", "Exit"};
    Color buttonColors[] = {BLUE, GREEN, YELLOW, RED};
    int tombolLebar = 200;
    int tombolLebarTerpilih = 220;
    int tombolTinggi = 40;
    int tombolTinggiTerpilih = 50;
    int tombolXNormal = SCREEN_WIDTH / 2 - tombolLebar / 2;
    int tombolXTerpilih = SCREEN_WIDTH / 2 - tombolLebarTerpilih / 2;
    int tombolY = SCREEN_HEIGHT / 2 - 60;

    // Menampilkan tombol menu
    for (int i = 0; i < TOTAL_BUTTONS; i++) {
        bool isSelected = (i == screen->index);
        int tombolX = isSelected ? tombolXTerpilih : tombolXNormal;
        int tombolHeight = isSelected ? tombolTinggiTerpilih : tombolTinggi;
        Color warna = buttonColors[i];

        // Efek highlight
        if (isSelected) {
            DrawRectangle(tombolX - 5, tombolY + (i * 50) - 5, tombolLebarTerpilih + 10, tombolTinggiTerpilih + 10, Fade(warna, 0.3f));
        }

        DrawRectangleLines(tombolX, tombolY + (i * 50), tombolLebarTerpilih, tombolHeight, warna);
        DrawText(menuItems[i], SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 20) / 2, 
                 tombolY + (i * 50) + 15, 20, isSelected ? WHITE : warna);
    }

    EndDrawing();
}


void HandleGameOverInput(ScreenControl *screen) {
    // Gambar layar Game Over
    DrawGameOverScreen(screen);
    
    // Navigasi menu
    if (IsKeyPressed(KEY_UP)) {
        screen->index = (screen->index == 0) ? TOTAL_BUTTONS - 1 : screen->index - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index = (screen->index == TOTAL_BUTTONS - 1) ? 0 : screen->index + 1;
    }
    
    // Eksekusi aksi saat ENTER ditekan
    if (IsKeyPressed(KEY_ENTER)) {
        switch (screen->index) {
            case 0:
                // Restart game, reset bola dan level
                screen->gameState = PLAY;
                break;
            case 1:
                // Menu pemilihan level
                screen->gameState = LEVEL_SELECTION;
                break;
            case 2:
                // Kembali ke menu utama
                screen->gameState = MENU;
                break;
            case 3:
                // Keluar dari permainan
                screen->gameState = EXIT;
                break;
        }
    }
}


void HapusLayarGameOver(LayarGameOver *layar) {
}
