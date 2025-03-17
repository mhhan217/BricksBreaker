#include "raylib.h"
#include "../Include/Zahwa.h"

#define MAKS_NYAWA 3

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

void InitLives(Lives* lives) {
    lives->jumlah_nyawa = MAKS_NYAWA;
    lives->heartIcon = LoadTexture("HeartPixel.png");
    if (!IsTextureReady(lives->heartIcon)) {
        TraceLog(LOG_ERROR, "Gagal menampilkan HeartPixel.png");
    }
    lives->posisi = (Vector){10, 10};
}

void DrawLives(const Lives* lives) {
    if (!IsTextureReady(lives->heartIcon)) return;

    int jarak = 5;
    int i;
    for (i = 0; i < lives->jumlah_nyawa; i++) {
        DrawTexture(lives->heartIcon,
                    lives->posisi.x + (i * (lives->heartIcon.width + jarak)),
                    lives->posisi.y, WHITE);
    }
}

void CekBolaJatuh(Lives* lives, Ball* ball) {
    if (ball->Posisi.y >= GetScreenHeight()) {
        lives->jumlah_nyawa--;

        ball->Posisi = (Vector2){400, 300};

        if (lives->jumlah_nyawa <= 0) {
            InitLives(lives);
        }
    }
}

void unloadLives(Lives *lives) {
    if (IsTextureReady(lives->heartIcon)) {
        UnloadTexture(lives->heartIcon);
        lives->heartIcon.id = 0; 
    }
}

