#ifndef ZAHWA_H
#define ZAHWA_H

#include "raylib.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Chinta.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
} Paddle;

typedef struct {
    int jumlah_nyawa;
    Texture2D heartIcon;
    Vector2 posisi;
} Lives;

typedef struct MenuNode {
    char *text;
    Color color;
    struct MenuNode *next;
} MenuNode;

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

void InitLives(Lives* lives, Vector2 Posisi);
void DrawLives(Lives* lives);
void UpdateLives(Lives* lives, Ball* ball);
void UnloadLives(Lives* lives);

void displayMenu(ScreenControl *screen);

#endif //ZAHWA_H

