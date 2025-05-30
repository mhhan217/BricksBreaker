//Faridha.h

#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"
#define DARKPINK (Color){199, 21, 133, 255};

typedef struct ColorNodeFaridha {
    Color warna;
    struct ColorNodeFaridha *next;
} ColorNodeFaridha;

typedef struct MenuNodeFaridha{
    char *namaMenu;
    struct MenuNodeFaridha *next;
} MenuNodeFaridha;

typedef struct LayarGameOver{
    char *pesan;  
    int indeksMenu;
    Color warnaTeks;
    MenuNodeFaridha *menuList;
    ColorNodeFaridha *warnaJudul;
    ColorNodeFaridha *warnaTombol;
} LayarGameOver;

void InisialisasiLayarGameOver(LayarGameOver *layar);
void DrawGameOverScreen(GameState *gameState, LayarGameOver *layar);
void HandleGameOverInput(GameState *gameState, LayarGameOver *layar);
void HapusLayarGameOver(LayarGameOver *layar);
void PauseGame();
void ResumeGame();
void ShowGameOver();
#endif