#ifndef ZAHWA_H
#define ZAHWA_H

#include "raylib.h"
#include "Konfigurasi.h"


void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

void InitLives(Lives* lives, Vector2 Posisi);
void DrawLives(Lives* lives);
void UpdateLives(Lives* lives, Ball* ball);
void UnloadLives(Lives* lives);


#endif // ZAHWA_H
