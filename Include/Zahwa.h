#ifndef ZAHWA_H
#define ZAHWA_H
#include "raylib.h"

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
}Paddle;

typedef struct {
    int jumlah_nyawa;
    Texture2D heartIcon;
    Vector2 posisi;
} Lives;

typedef struct MenuNodeZahwa{
    const char* menuOption;
    Color highlightColor;
    struct MenuNodeZahwa* next;
} MenuNodeZahwa;

void displayMenuWithGraphics();

typedef struct Ball Ball;
void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

void InitLives(Lives* lives, Vector2 Posisi);
void DrawLives(Lives* lives);
void UpdateLives(Lives* lives, Ball* ball);
void UnloadLives(Lives* lives);

#endif //ZAHWA_H

