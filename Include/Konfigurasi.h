//
// Created by Arman on 2/23/2025.
//

#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60

typedef enum {
MENU,
SETTINGS,
INFO,
LEVEL_SELECTION,
LOADING,
PLAY,
PAUSE,
GAME_OVER,
EXIT
} GameState;

typedef struct {
    GameState gameState; // Status utama game
    int index;   // Indeks pilihan yang sedang dipilih
} ScreenControl;

#endif //KONFIGURASI_H