#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800
#define TARGET_FPS 60

typedef enum {
MENU,
SETTINGS,
INFO,
LEVEL_SELECTION,
RESTART,
PLAY,
PAUSE,
GAME_OVER,
EXIT
} GameState;

typedef struct
{
    int index;
}ScreenControl;


#endif //KONFIGURASI_H
