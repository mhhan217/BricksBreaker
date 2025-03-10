#include "raylib.h"
#include "../Include/Hanif.h"
#include <math.h>
//struct ball

//mengatur atribut atribut bola
void initBall(Ball* ball, Vector2 ballSpeed, Paddle* paddle) {
    ball->Speed = ballSpeed;
    ball->Radius = 10;
    ball->Color = RAYWHITE;
    ball->Active = true;
    ball->Released = false; // Pastikan bola belum dilepas
    ball->Position.x = paddle->Position.x + paddle->Ukuran.x / 2;
    ball->Position.y = paddle->Position.y - ball->Radius;
}


//
void updateBall(Ball* ball, Paddle* paddle,Vector2 SpeedBola) {
    if (!ball->Active) return; // Jika bola tidak aktif, tidak ditampilkan atau diupdate

    // Geser semua Position Effect (jejak)
    for (int i = LONG_EFFECT - 1; i > 0; i--) {
        ball->Effect[i] = ball->Effect[i - 1];
    }
    ball->Effect[0] = ball->Position;

    // Jika bola belum dilepas, Positionnya mengikuti paddle
    if (!ball->Released) {
        ball->Position.x = paddle->Position.x + paddle->Ukuran.x / 2;
        ball->Position.y = paddle->Position.y -ball->Radius;
        ball->Speed = SpeedBola;

        // Tekan spasi untuk melepaskan bola
        if (IsKeyPressed(KEY_SPACE)) {
            ball->Released = true;
        }
    }

    if (ball->Released) {
        // Update Position bola
        ball->Position.x += ball->Speed.x;
        ball->Position.y += ball->Speed.y;

        // Pantulan dari dinding kiri dan kanan
        if (ball->Position.x - ball->Radius <= 0 || ball->Position.x + ball->Radius >= GetScreenWidth()) {
            ball->Speed.x *= -1;
        }

        // Pantulan dari atas layar
        if (ball->Position.y - ball->Radius <= 0) {
            ball->Speed.y *= -1;
        }

        // Pantulan dari paddle
        if (ball->Position.y + ball->Radius >= paddle->Position.y && ball->Position.x >= paddle->Position.x &&
            ball->Position.x <= paddle->Position.x + paddle->Ukuran.x) {

            // Hitung offset dari tengah paddle
            float offset = (ball->Position.x - (paddle->Position.x + paddle->Ukuran.x / 2)) / (paddle->Ukuran.x / 2);

            // jika boal teapt ditengah maka x akan di jadikan 0
            if (fabs(offset) < 0.1f) {
                ball->Speed.x = 0;
                ball->Speed.y = -fabs(ball->Speed.y);
            } else {
                // jika bola tidak tepat ditengah maka x akan diubah
                ball->Speed.x = offset * 5;
                ball->Speed.y = -fabs(ball->Speed.y);
            }

            // jika Speed x bola dibawah 2.0f dan diatas 0.1f
            if (fabs(ball->Speed.x) < 2.0f &&fabs(ball->Speed.x) >0.1f ) {
                ball->Speed.x = (ball->Speed.x > 0) ? 3.0f : -3.0f;//maka arah bola x bola akan diubah menjadi +3 atau -3
            }
        }

        // Jika bola jatuh ke bawah, reset Position ke paddle
        if (ball->Position.y + ball->Radius >= GetScreenHeight()) {
            ball->Released = false;
        }
    }
}


void drawBall(Ball ball) {
    if (ball.Active) {
        // Gambar Effect bola
        for (int i = 0; i < LONG_EFFECT; i++) { //membuat Effect jejak lingkaran bola dari array Effect
            float jejak_Effect = (float)(LONG_EFFECT - i) / LONG_EFFECT;//jika Effect[i] lebih besar makan akan semakin transparan
            Color EffectColor = Fade(ball.Color, jejak_Effect);//Fade digunakan untuk membuat Color bola semakin transparan dengan float jejak_Effect
            DrawCircleV(ball.Effect[i], ball.Radius - i * 0.3,EffectColor);
        }
        // Gambar bola
        DrawCircleV(ball.Position, ball.Radius, ball.Color);//menggambar bola
    }
}

void setSpeedBall(Ball* ball,Level* level) {
    switch (level->DifficultLevel) {
        case EASY:  ball -> Speed = (Vector2){0, -10};break;
        case MEDIUM: ball -> Speed = (Vector2){0, -15};break;
        case HARD: ball -> Speed = (Vector2){0, -20};break;
        default: ball -> Speed = (Vector2){0, -10}; // Default ke EASY
    }
}

Vector2 getSpeedBall(Ball* ball) {
    return ball->Speed;
}




