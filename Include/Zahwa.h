#ifndef ZAHWA_H
#define ZAHWA_H

#include "raylib.h"
#include "Konfigurasi.h"

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

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

void InitLives(Lives* lives);
void DrawLives(const Lives* lives);
void CekBolaJatuh(Lives* lives,Ball* ball);
void unloadLives(Lives* lives);

#endif // ZAHWA_H
