#include "raylib.h"
#include "Zahwa.h"

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

void InitLives(Lives* lives, Vector2 Posisi) {
    lives->jumlah_nyawa = MAKS_NYAWA;
    lives->posisi = (Vector2){0, 0};  // Posisi ikon nyawa di pojok kiri atas
    lives->heartIcon = LoadTexture("HeartPixel.png");
    if (!IsTextureValid(lives->heartIcon)) {
        TraceLog(LOG_ERROR, "Gagal memuat HeartPixel.png"); // Jika file tidak ditemukan
    }
}

void DrawLives(Lives* lives) {
    if (IsTextureValid(lives->heartIcon)) {
        int jarak = 2;
        for (int i = 0; i < lives->jumlah_nyawa; i++) {
            DrawTexture(lives->heartIcon,
                    lives->posisi.x + (i * (lives->heartIcon.width + jarak)),
                    lives->posisi.y, WHITE);
        }
    } 
}

void UpdateLives(Lives* lives, Ball* ball) {
    // Cek bola jatuh ke bawah layar 
    if (lives->jumlah_nyawa > 0 && ball->Position.y + ball->Radius >= GetScreenHeight()) {
        lives->jumlah_nyawa--;  
        // Nyawa masih ada
        if (lives->jumlah_nyawa <= 0) {
            lives->jumlah_nyawa = 0;          
        }
    }
}    

// Membebaskan memori dari tekstur ikon nyawa setelah permainan selesai
void UnloadLives(Lives* lives) {
    if (IsTextureValid(lives->heartIcon)) {
        UnloadTexture(lives->heartIcon);
        lives->heartIcon.id = 0;
    }
}