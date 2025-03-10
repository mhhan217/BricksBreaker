#ifndef ZAHWA_H
#define ZAHWA_H
#include "raylib.h"

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
}Paddle;

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* Paddle);
void DrawPaddle(Paddle Paddle);

#endif //ZAHWA_H

