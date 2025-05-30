#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Include/Faridha.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Hanif.h"
#include "../Include/Billy.h"

#define TOTAL_BUTTONS 4

// GameState*  gameState;
bool isPaused = false;
int selectedButton = 0;
int currentIndex = 0;
// LayarGameOver *layar;

void InisialisasiLayarGameOver(LayarGameOver *layar) {
const char *pesanGameOver = "GAME OVER";
    layar->pesan = malloc(strlen(pesanGameOver) + 1);
    strcpy(layar->pesan, pesanGameOver);
    layar->warnaTeks = RED;
    layar->indeksMenu = 0;

    // Inisialisasi linked list untuk warna judul
    layar->warnaJudul = NULL;
    ColorNodeFaridha* nodeAwalJudul = NULL;

    // Membuat node warna judul
    ColorNodeFaridha* nodePink = malloc(sizeof(ColorNodeFaridha));
    nodePink->warna = DARKPINK;
    nodePink->next = NULL;
    layar->warnaJudul = nodePink;
    nodeAwalJudul = nodePink;

    ColorNodeFaridha* nodeBiru = malloc(sizeof(ColorNodeFaridha));
    nodeBiru->warna = BLUE;
    nodeBiru->next = NULL;
    nodeAwalJudul->next = nodeBiru;
    nodeAwalJudul = nodeBiru;

    ColorNodeFaridha* nodeHijau = malloc(sizeof(ColorNodeFaridha));
    nodeHijau->warna = GREEN;
    nodeHijau->next = NULL;
    nodeAwalJudul->next = nodeHijau;
    nodeAwalJudul = nodeHijau;

    ColorNodeFaridha* nodeKuning = malloc(sizeof(ColorNodeFaridha));
    nodeKuning->warna = YELLOW;
    nodeKuning->next = NULL;
    nodeAwalJudul->next = nodeKuning;
    nodeAwalJudul = nodeKuning; 

    // Inisialisasi linked list untuk warna tombol
    layar->warnaTombol = NULL;
    ColorNodeFaridha* nodeAwalTombol = NULL;

    // Membuat node warna tombol
    ColorNodeFaridha* tombolPink = malloc(sizeof(ColorNodeFaridha));
    tombolPink->warna = DARKPINK;
    tombolPink->next = NULL;
    layar->warnaTombol = tombolPink;
    nodeAwalTombol = tombolPink;

    ColorNodeFaridha* tombolBiru = malloc(sizeof(ColorNodeFaridha));
    tombolBiru->warna = BLUE;
    tombolBiru->next = NULL;
    nodeAwalTombol->next = tombolBiru;
    nodeAwalTombol = tombolBiru;

    ColorNodeFaridha* tombolHijau = malloc(sizeof(ColorNodeFaridha));
    tombolHijau->warna = GREEN;
    tombolHijau->next = NULL;
    nodeAwalTombol->next = tombolHijau;
    nodeAwalTombol = tombolHijau;

    ColorNodeFaridha* tombolKuning = malloc(sizeof(ColorNodeFaridha));
    tombolKuning->warna = YELLOW;
    tombolKuning->next = NULL;
    nodeAwalTombol->next = tombolKuning;
    nodeAwalTombol = tombolKuning; 

    // Inisialisasi linked list untuk menu
    layar->menuList = NULL;
    MenuNodeFaridha* currentMenuItem = NULL;

    // Membuat node menu
    MenuNodeFaridha* menuNode1 = malloc(sizeof(MenuNodeFaridha));
    const char *judulMenu1 = "Restart";
    menuNode1->namaMenu = malloc(strlen(judulMenu1) + 1);
    strcpy(menuNode1->namaMenu, judulMenu1);
    menuNode1->next = NULL;
    layar->menuList = menuNode1;
    currentMenuItem = menuNode1;

    MenuNodeFaridha* menuNode2 = malloc(sizeof(MenuNodeFaridha));
    const char *judulMenu2 = "Select Level";
    menuNode2->namaMenu = malloc(strlen(judulMenu2) + 1);
    strcpy(menuNode2->namaMenu, judulMenu2);
    menuNode2->next = NULL;
    currentMenuItem->next = menuNode2;
    currentMenuItem = menuNode2;

    MenuNodeFaridha* menuNode3 = malloc(sizeof(MenuNodeFaridha));
    const char *judulMenu3 = "Menu";
    menuNode3->namaMenu = malloc(strlen(judulMenu3) + 1);
    strcpy(menuNode3->namaMenu, judulMenu3);
    menuNode3->next = NULL;
    currentMenuItem->next = menuNode3;
    currentMenuItem = menuNode3;

    MenuNodeFaridha* menuNode4 = malloc(sizeof(MenuNodeFaridha));
    const char *judulMenu4 = "Exit";
    menuNode4->namaMenu = malloc(strlen(judulMenu4) + 1);
    strcpy(menuNode4->namaMenu, judulMenu4);
    menuNode4->next = NULL;
    currentMenuItem->next = menuNode4;
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

void DrawGameOverScreen(GameState *gameState, LayarGameOver *layar) {
// Judul game
    const char *judulGame = "Bricks Breaker Game";
    int posisiXJudulGame = SCREEN_WIDTH / 2 - MeasureText(judulGame, 30) / 2;
    int posisiYJudulGame = 50;
    int jarakHuruf = 5;
    int ukuranHurufJudul = 30;

    ColorNodeFaridha* warnaNode = layar->warnaJudul;
    for (int i = 0; i < strlen(judulGame); i++) {
        if (warnaNode == NULL) warnaNode = layar->warnaJudul;

        DrawText(TextFormat("%c", judulGame[i]), posisiXJudulGame, posisiYJudulGame, ukuranHurufJudul, warnaNode->warna);
        posisiXJudulGame += MeasureText(TextFormat("%c", judulGame[i]), ukuranHurufJudul) + jarakHuruf;
        warnaNode = warnaNode->next;
    }

    // Game Over
    const char *judul = layar->pesan;
    int posisiXJudul = SCREEN_WIDTH / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = 130;
    int ukuranHurufGO = 40;
    DrawText(judul, posisiXJudul, posisiYJudul, ukuranHurufGO, layar->warnaTeks);

    //Menu
    int posisiXMenu = SCREEN_WIDTH / 2; 
    int posisiYMenu = 220;
    int jarakAntarMenu = 60; 
    int ukuranHuruf = 30;

    ColorNodeFaridha* buttonNode = layar->warnaTombol;
    MenuNodeFaridha* menuNode = layar->menuList;

    int i = 0;
    while (buttonNode != NULL && menuNode != NULL) {
        bool isSelected = (i == currentIndex);
        Color warnaGambar = isSelected ? buttonNode->warna : WHITE;

        // Posisi menu
        int itemY = posisiYMenu + (i * jarakAntarMenu);
        DrawText(menuNode->namaMenu, posisiXMenu - MeasureText(menuNode->namaMenu, ukuranHuruf) / 2, 
                itemY, ukuranHuruf, warnaGambar);

        buttonNode = buttonNode->next;
        menuNode = menuNode->next;
        i++;
    }
}

void HandleGameOverInput(GameState *gameState, LayarGameOver *layar) {
    int menuCount = 0;
    MenuNodeFaridha* menuNode = layar->menuList;
    while (menuNode != NULL) {
        menuCount++;
        menuNode = menuNode->next;
    }

    if (IsKeyPressed(KEY_UP)) {
        currentIndex = (currentIndex == 0) ? menuCount - 1 : currentIndex - 1;
        layar->indeksMenu = currentIndex;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        currentIndex = (currentIndex == menuCount - 1) ? 0 : currentIndex + 1;
        layar->indeksMenu = currentIndex;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (currentIndex) {
            case 0: *gameState = RESTART; break;
            case 1: *gameState = LEVEL_SELECTION; break;
            case 2: *gameState = MENU; break;
            case 3: CloseWindow(); break;
        }
    }
}



void HapusLayarGameOver(LayarGameOver *layar) {
    if (layar == NULL) return;
    
    if (layar->pesan != NULL) {
        free(layar->pesan);
        layar->pesan = NULL;
    }

    ColorNodeFaridha* current = layar->warnaJudul;
    while (current != NULL) {
        ColorNodeFaridha* temp = current;
        current = current->next;
        free(temp);
    }
    layar->warnaJudul = NULL;

    current = layar->warnaTombol;
    while (current != NULL) {
        ColorNodeFaridha* temp = current;
        current = current->next;
        free(temp);
    }
    layar->warnaTombol = NULL;

    MenuNodeFaridha* menu = layar->menuList;
    while (menu != NULL) {
        MenuNodeFaridha* temp = menu;
        menu = menu->next;
        if (temp->namaMenu != NULL) {
            free(temp->namaMenu);
            temp->namaMenu = NULL;
        }
        free(temp);
    }
    layar->menuList = NULL;
}
