#ifndef KONFIGURASI_H
#define KONFIGURASI_H
#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60
#define LONG_EFFECT 15
#define DIFFICULTY_LEVELS 3
#define BRICK_LEBAR 3
#define BRICK_TINGGI 3
#define BRICK_PADDING 5
#define TOTAL_LEVELS 30
#define BRICK_COLS 30
#define BRICK_ROWS 55
#define DIFFICULTY_LEVELS 3
#define BRICK_WIDTH 10
#define BRICK_HEIGHT 10
#define BRICK_PADDING 5
#define TOTAL_LEVELS 30

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
    int jumlah_nyawa;
    Texture2D heartIcon;
    Vector2 posisi;
} Lives;

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
} Paddle;


typedef struct {
    Vector2 position;
    Rectangle kotak;
    float width;
    float heigth;
    Color color;
    bool isActive;
    bool isIndestructible;
    bool on;
} Brick;

Brick bricks[BRICK_ROWS][BRICK_COLS];

typedef enum {
    EASY, MEDIUM, HARD
} Difficulty;

typedef struct {
    int NumberLevel;
    Difficulty DifficultLevel;
    int brickPattern[BRICK_ROWS][BRICK_COLS];
}Level;

typedef struct {
    Vector2 Position;
    Vector2 Speed;
    float Radius;
    Vector2 Effect[LONG_EFFECT];
    Color Color;
    bool Active;
    bool Released;
} Ball;

typedef enum {
    POWER_NONE,
    POWER_ENLARGE_PADDLE,
    POWER_SHRINK_PADDLE,
    POWER_SPEED_UP_BALL,
    POWER_SLOW_DOWN_BALL,
    POWER_EXTRA_LIFE
} PowerUpType;

typedef struct PowerUp {
    Vector2 position;
    Vector2 speed;
    int radius;
    int type;
    bool active;
} PowerUp;

#endif //KONFIGURASI_H