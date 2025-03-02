#include "raylib.h"
#include "Hanif.h"
#include <math.h>

//mengatur atribut atribut bola
void InitBall(Ball* ball,Vector2 PosisiAwal) {
    ball->Posisi = PosisiAwal;//menentukan posisi awal bola
    ball->Kecepatan = (Vector2){0, -10}; // Kecepatan awal bola
    ball->Radius = 10;//besar bola
    ball->Warna = RAYWHITE;//warna bola
    ball->Aktif = true;//status bola apakah aktif atau tidak untuk fitur bola menjadi lebih dari 1

    for (int i = 0; i < PANJANG_EFEK; i++) {
        ball->Efek[i] = PosisiAwal;//jejak atau array efek bola akan berada di posisi awal bola(mengikuti bola) untuk memunculkan efek sebanyak jumlahefek
    }
}

//
void UpdateBall(Ball* ball) {
    if (!ball->Aktif) return;//jika bola tidak aktif maka bola akan hilang(tidak ditampilkan atau diupdate)

    // Geser semua posisi efek (jejak)
    for (int i = PANJANG_EFEK - 1; i > 0; i--) {
        ball->Efek[i] = ball->Efek[i - 1];
    }
    ball->Efek[0] = ball->Posisi;

    // Update posisi bola
    ball->Posisi.x += ball->Kecepatan.x;//update posisi bola jika keatas atau bawah
    ball->Posisi.y += ball->Kecepatan.y;//update posisi bola jika ke kanan atau kiri

    // untuk mengatasi pantulan dari dinding kiri dan kanan
    if (ball->Posisi.x - ball->Radius <= 0 || ball->Posisi.x + ball->Radius >= GetScreenWidth()) {
        ball->Kecepatan.x *= -1;
    }

    // untuk mengatasi pantulan dari atas layar
    if (ball->Posisi.y - ball->Radius <= 0) {
        ball->Kecepatan.y *= -1;
    }

    // untuk mengatasi Jika bola jatuh ke bawah maka akan  mereset posisi
    if (ball->Posisi.y + ball->Radius >= GetScreenHeight()) {
        ball->Posisi.y = GetScreenHeight() / 2;
        ball->Posisi.x = GetScreenWidth() / 2;
        ball->Kecepatan = (Vector2){0, -10}; // Reset kecepatan awal
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





