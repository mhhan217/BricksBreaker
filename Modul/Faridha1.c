//Faridha.c

#include "raylib.h"
#include "Faridha.h"
#include "Konfigurasi.h"
#include <stdlib.h>
#include "Billy.h"
#include "Zidan.h"

int playerLives = 3;
// Variabel global
PowerUp powerUps[MAX_POWERUPS];
Texture2D powerUpTextures[3];
Ball* balls;

// Fungsi untuk memuat texture power-up
void LoadPowerUpTextures() {
    powerUpTextures[POWER_EXTRA_LIFE] = LoadTexture("assets/love.png");
    powerUpTextures[POWER_EXTRA_BALL] = LoadTexture("assets/ball.png");
    powerUpTextures[POWER_ENLARGE_PADDLE] = LoadTexture("assets/paddle.png");
}

// Fungsi untuk menginisialisasi power-up
void InitializePowerUp(PowerUp *powerUp) {
    powerUp->posisi = (Vector2){ GetRandomValue(0, SCREEN_WIDTH - 50), GetRandomValue(-500, -50) };
    powerUp->kecepatan = (Vector2){ 0, GetRandomValue(1, 3) };
    powerUp->radius = 15;
    powerUp->tipe = GetRandomValue(0, 2);  // Random jenis power-up
    powerUp->aktif = true;
    powerUp->durasi = 5.0f;  // Durasi default 5 detik
    powerUp->waktu = 0.0f;     // Timer untuk menghitung durasi
}

// Fungsi untuk mengupdate power-up
void UpdatePowerUp(PowerUp *powerUp, float deltaTime) {
    if (!powerUp->aktif) return;

    // Gerakkan power-up ke bawah
    powerUp->posisi.y += powerUp->kecepatan.y * deltaTime * 60;

    // Cek jika power-up jatuh keluar layar
    if (powerUp->posisi.y > SCREEN_HEIGHT) {
        InitializePowerUp(powerUp);
    }

    // Cek tabrakan dengan paddle
    if (CheckCollisionCircleRec(powerUp->posisi, powerUp->radius, Paddle)) {
        switch (powerUp->tipe) {
            case POWER_EXTRA_LIFE:
                playerLives++;
                break;
            case POWER_EXTRA_BALL:
                // Buat semua bola menjadi kuat selama beberapa detik
                for (int i = 0; i < numBalls; i++) {
                    balls[i].isStrong = true;
                    balls[i].strongTime = 5.0f;  // Durasi efek kuat: 5 detik
                }
                break;
            case POWER_ENLARGE_PADDLE:
                paddle.width += 20;
                powerUp->waktu = 0.0f;  // Reset timer
                break;
        }
        powerUp->aktif = false;  // Matikan power-up setelah diambil
    }

    // Update timer untuk power-up yang bersifat sementara
    if (powerUp->tipe == POWER_ENLARGE_PADDLE && paddle.width > 100) {
        powerUp->waktu += deltaTime;
        if (powerUp->waktu >= powerUp->durasi) {
            paddle.width = 100;  // Kembalikan ukuran paddle ke normal
        }
    }
}

// Fungsi untuk merender power-up
void DrawPowerUp(PowerUp powerUp) {
    if (powerUp.aktif) {
        DrawTexture(powerUpTextures[powerUp.tipe], (int)powerUp.posisi.x, (int)powerUp.posisi.y, WHITE);
    }
}

// Fungsi untuk membersihkan resource
void CloseGame() {
    for (int i = 0; i < 3; i++) {
        UnloadTexture(powerUpTextures[i]);
    }
}

// Fungsi untuk menghancurkan bricks di sekitarnya
void DestroyBricksAround(Balok brick) {
    for (int i = 0; i < NUM_BRICKS; i++) {
        if (bricks[i].active && CheckCollisionRecs(brick.kotak, bricks[i].kotak)) {
            bricks[i].active = false;  // Hancurkan brick
        }
    }
}