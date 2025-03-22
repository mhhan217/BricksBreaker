#ifndef ZAHWA_H
#define ZAHWA_H

#include "raylib.h"

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

// typedef struct{
//     Vector2 Posisi;
//     Vector2 Kecepatan;
//     float Radius;
//     Color Warna;
//     bool Aktif;
//     bool Released;
// } Ball;

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

void InitLives(Lives* lives, Vector2 Posisi, int jumlah_nyawa);
void DrawLives(Lives* lives);
void UpdateLives(Lives* lives, Ball* ball);
void UnloadLives(Lives* lives);

#endif //ZAHWA_H

