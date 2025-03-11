#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

extern int gameState;

typedef struct {
    char pesan[20];  
    int indeksMenu;
    Color warnaTeks;
} LayarGameOver;



void InisialisasiLayarGameOver(LayarGameOver *layar);
void DrawGameOverScreen(ScreenControl *screen);
void HandleGameOverInput(ScreenControl *screen);
void HapusLayarGameOver(LayarGameOver *layar);
void PauseGame();
void ResumeGame();
void BackToMenu();
void ShowGameOver();


#endif
