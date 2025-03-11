#include "raylib.h"
#include "Hanif.h"
#include <math.h>

//mengatur atribut atribut bola
void InitBall(Ball* ball, Vector2 KecepatanBola, Paddle* paddle) {
    ball->Kecepatan = KecepatanBola;
    ball->Radius = 10;
    ball->Warna = RAYWHITE;
    ball->Aktif = true;
    ball->Released = false; // Pastikan bola belum dilepas
    ball->Posisi.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
    ball->Posisi.y = paddle->Posisi.y - ball->Radius;
}


//
void UpdateBall(Ball* ball, Paddle* paddle,Vector2 KecepatanBola) {
    if (!ball->Aktif) return; // Jika bola tidak aktif, tidak ditampilkan atau diupdate

    // Geser semua posisi efek (jejak)
    for (int i = PANJANG_EFEK - 1; i > 0; i--) {
        ball->Efek[i] = ball->Efek[i - 1];
    }
    ball->Efek[0] = ball->Posisi;

    // Jika bola belum dilepas, posisinya mengikuti paddle
    if (!ball->Released) {
        ball->Posisi.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
        ball->Posisi.y = paddle->Posisi.y -ball->Radius;
        ball->Kecepatan = KecepatanBola;

        // Tekan spasi untuk melepaskan bola
        if (IsKeyPressed(KEY_SPACE)) {
            ball->Released = true;
        }
    }

    if (ball->Released) {
        // Update posisi bola
        ball->Posisi.x += ball->Kecepatan.x;
        ball->Posisi.y += ball->Kecepatan.y;

        // Pantulan dari dinding kiri dan kanan
        if (ball->Posisi.x - ball->Radius <= 0 || ball->Posisi.x + ball->Radius >= GetScreenWidth()) {
            ball->Kecepatan.x *= -1;
        }

        // Pantulan dari atas layar
        if (ball->Posisi.y - ball->Radius <= 0) {
            ball->Kecepatan.y *= -1;
        }

        // Pantulan dari paddle
        if (ball->Posisi.y + ball->Radius >= paddle->Posisi.y && ball->Posisi.x >= paddle->Posisi.x &&
            ball->Posisi.x <= paddle->Posisi.x + paddle->Ukuran.x) {

            // Hitung offset dari tengah paddle
            float offset = (ball->Posisi.x - (paddle->Posisi.x + paddle->Ukuran.x / 2)) / (paddle->Ukuran.x / 2);

            // jika boal teapt ditengah maka x akan di jadikan 0
            if (fabs(offset) < 0.1f) {
                ball->Kecepatan.x = 0;
                ball->Kecepatan.y = -fabs(ball->Kecepatan.y);
            } else {
                // jika bola tidak tepat ditengah maka x akan diubah
                ball->Kecepatan.x = offset * 5;
                ball->Kecepatan.y = -fabs(ball->Kecepatan.y);
            }

            // jika kecepatan x bola dibawah 2.0f dan diatas 0.1f
            if (fabs(ball->Kecepatan.x) < 2.0f &&fabs(ball->Kecepatan.x) >0.1f ) {
                ball->Kecepatan.x = (ball->Kecepatan.x > 0) ? 3.0f : -3.0f;//maka arah bola x bola akan diubah menjadi +3 atau -3
            }
        }

        // Jika bola jatuh ke bawah, reset posisi ke paddle
        if (ball->Posisi.y + ball->Radius >= GetScreenHeight()) {
            ball->Released = false;
        }
    }
}


void DrawBall(Ball ball) {
    if (ball.Aktif) {
        // Gambar efek bola
        for (int i = 0; i < PANJANG_EFEK; i++) { //membuat efek jejak lingkaran bola dari array efek
            float jejak_efek = (float)(PANJANG_EFEK - i) / PANJANG_EFEK;//jika efek[i] lebih besar makan akan semakin transparan
            Color efekWarna = Fade(ball.Warna, jejak_efek);//Fade digunakan untuk membuat warna bola semakin transparan dengan float jejak_efek
            DrawCircleV(ball.Efek[i], ball.Radius - i * 0.3,efekWarna);
        }
        // Gambar bola
        DrawCircleV(ball.Posisi, ball.Radius, ball.Warna);//menggambar bola
    }
}

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan) {
    Paddle->Posisi = posisiAwal;
    Paddle->Ukuran = ukuran;
    Paddle->Kecepatan = kecepatan;
    Paddle->Warna = RAYWHITE;
}

void UpdatePaddle(Paddle* Paddle) {
    if (IsKeyDown(KEY_LEFT) && Paddle->Posisi.x > 0) {
        Paddle->Posisi.x -= Paddle->Kecepatan;
    }
    if (IsKeyDown(KEY_RIGHT) && Paddle->Posisi.x + Paddle->Ukuran.x < GetScreenWidth()) {
        Paddle->Posisi.x += Paddle->Kecepatan;
    }
}

void DrawPaddle(Paddle Paddle) {
    DrawRectangleV(Paddle.Posisi, Paddle.Ukuran, Paddle.Warna);
}






