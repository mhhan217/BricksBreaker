#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60

typedef enum {
    MENU,
    HIGH_SCORE,
    SETTINGS,
    INFO,
    PLAY,
    PLAYING, 
    PAUSE,
    PAUSED, 
    GAME_OVER,
    EXIT,
    LEVEL_SELECTION 
} GameState;

typedef struct {
    GameState gameState; 
    int index;   
} ScreenControl;

#endif
