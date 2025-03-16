#ifndef HANIF_H
#define HANIF_H
#include "raylib.h"

#define PANJANG_EFEK 15

typedef struct{

    Vector2 Posisi;
    Vector2 Kecepatan;
    float Radius;
    Vector2 Efek[PANJANG_EFEK];
    Color Warna;
    bool Aktif;
    bool Released;

}Ball;

typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
} Paddle;

void InitPaddle(Paddle* paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* paddle);
void DrawPaddle(Paddle paddle);


void InitBall(Ball* ball,Vector2 KecepatanBola,Paddle* paddle   );
void UpdateBall(Ball* ball,Paddle* paddle,Vector2 kecepatanBola);
void DrawBall(Ball ball);


#endif //HANIF_H
