#ifndef KONFIGURASI_H
#define KONFIGURASI_H
#include "raylib.h"
#include "Hanif.h"
#include "Zahwa.h"
#include "Faridha.h"
#include "Billy.h"
#include "Zidan.h"
#include "Chinta.h"
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
    GameState state;
    Ball ball;
    Paddle paddle;
    Brick bricks[BRICK_ROWS][BRICK_COLS];
    PowerUp powerUp;
    Difficulty difficulty;
    Level level;
    Lives lives;
    float volume;
    bool isMuted;
    ScreenControl screen;  // Tambahkan ScreenControl di dalam Game
} Game;






#endif //KONFIGURASI_H