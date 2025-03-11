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
    GameState gameState; //untuk menentukan gamestate
    int index;   // untuk menentukan index yang dipilih pada tiap tiap gamestate
} ScreenControl;

#endif //KONFIGURASI_H