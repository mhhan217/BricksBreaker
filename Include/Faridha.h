#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

//Warna
#define DARKPINK (Color){199, 21, 133, 255}

typedef struct {
    GameState gameState; 
    int index;   
} ScreenControl;

typedef struct ColorNode {
    Color warna;
    struct ColorNode *next;
} ColorNode;

typedef struct MenuNode {
    char *namaMenu;
    struct MenuNode *next;
} MenuNode;

typedef struct {
    char *pesan;  
    int indeksMenu;
    Color warnaTeks;
    MenuNode *menuList;
    ColorNode *warnaJudul;
    ColorNode *warnaTombol;
} LayarGameOver;

void InisialisasiLayarGameOver(LayarGameOver *layar);
void DrawGameOverScreen(GameState *gameState);
void HandleGameOverInput(GameState *gameState);
void HapusLayarGameOver(LayarGameOver *layar);
void PauseGame();
void ResumeGame();
void ShowGameOver();

#endif
