//
// Created by Arman on 2/23/2025.
//

#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60

#define JUMLAH_BARIS 5
#define JUMLAH_KOLOM 10

#define BRICK_LEBAR 50
#define BRICK_TINGGI 20


typedef enum {
    MENU,
    HIGH_SCORE,
    SETTINGS,
    INFO,
    PLAY,
    PAUSE,
    GAME_OVER,
    EXIT
} GameState;
#endif //KONFIGURASI_H
