//
// Created by Arman on 2/23/2025.
//

#ifndef KONFIGURASI_H
#define KONFIGURASI_H
#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60
#define LONG_EFFECT 15

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

typedef struct {
    Vector2 Position;
    Vector2 Speed;
    float Radius;
    Vector2 Effect[LONG_EFFECT];
    Color Color;
    bool Active;
    bool Released;
} Ball;

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
} Paddle;


#endif //KONFIGURASI_H