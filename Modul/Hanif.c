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
void updateBall(Ball* ball, Paddle* paddle, Vector2 SpeedBola) {
    if (!ball->Active) return; // Jika bola tidak aktif, tidak ditampilkan atau diupdate

    // Geser semua Position Effect (jejak)
    for (int i = LONG_EFFECT - 1; i > 0; i--) {
        ball->Effect[i] = ball->Effect[i - 1];
    }
    ball->Effect[0] = ball->Position;

    // Jika bola belum dilepas, posisi bola mengikuti paddle
    if (!ball->Released) {
        ball->Position.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
        ball->Position.y = paddle->Posisi.y - ball->Radius;
        ball->Speed = SpeedBola;

        // Tekan spasi untuk melepaskan bola
        if (IsKeyPressed(KEY_SPACE)) {
            ball->Released = true;
        }
    }

    if (ball->Released) {
        // Update posisi bola
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
        if (ball->Position.y + ball->Radius >= paddle->Posisi.y &&
            ball->Position.x >= paddle->Posisi.x &&
            ball->Position.x <= paddle->Posisi.x + paddle->Ukuran.x) {

            // menghitung posisi bola saat mengenai paddle dari (-1.0 ke 1.0)
            float posisiPantulan = (ball->Position.x - (paddle->Posisi.x + paddle->Ukuran.x / 2)) / (paddle->Ukuran.x / 2);

            // menghitung sudut pantulan dari -45° hingga 45°
            float sudutPantulan = posisiPantulan * 45 * (PI / 180.0f);  // Konversi ke radian

            // menghitung kecepatan dan arah bola menggunakan sin dan cos agar lebih realistis
            float speedTotal = sqrtf(ball->Speed.x * ball->Speed.x + ball->Speed.y * ball->Speed.y);//meghitung kecepatan bola(vektor) sebelum mengenai paddle dengan (a^2 + b^2)
            ball->Speed.x = sinf(sudutPantulan) * speedTotal; //menentukan berapa kemiringan pantulan bola setelah mengenai paddle
            ball->Speed.y = -cosf(sudutPantulan) * speedTotal;  // agar bola selalu ke atas setelah kena paddle

            // jika kecepatan bola terlalu kecil
            if (fabs(ball->Speed.x) < 2.0f) {
                ball->Speed.x = (ball->Speed.x > 0) ? 2.0f : -2.0f; //maka akan diubah ke 2 atau -2            }
            if (fabs(ball->Speed.y) < 3.0f) {
                ball->Speed.y = (ball->Speed.y > 0) ? 3.0f : -3.0f;//maka akan diubah ke 3 atau -3
            }
        }

        // Jika bola jatuh ke bawah, reset posisi ke paddle
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




