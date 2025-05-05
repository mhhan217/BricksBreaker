#include "raylib.h"
#include "Faridha.h"
#include "Konfigurasi.h"
#include <stdlib.h>

#define MAX_POWERUPS 5

// Struktur array untuk menyimpan beberapa power-up
PowerUp powerUps[MAX_POWERUPS];

// Deklarasi variabel powerUpTexture hanya jika belum ada di tempat lain
Texture2D powerUpTexture;

// Fungsi untuk menginisialisasi power-up
void InitializePowerUp(PowerUp *powerUp) {
    // Pastikan tekstur hanya dimuat sekali
    if (powerUpTexture.id == 0) {
        powerUpTexture = LoadTexture("assets/love.png");
    }

    powerUp->position.x = GetRandomValue(0, SCREEN_WIDTH - 50);
    powerUp->position.y = GetRandomValue(-500, -50);
    powerUp->speed.x = 0; 
    powerUp->speed.y = GetRandomValue(1, 3);
    powerUp->radius = 15;
    powerUp->type = GetRandomValue(POWER_ENLARGE_PADDLE, POWER_EXTRA_LIFE); 
    powerUp->active = true;
}

// Fungsi untuk memperbarui posisi power-up
void UpdatePowerUp(PowerUp *powerUp) {
    if (powerUp->active) {
        powerUp->position.y += powerUp->speed.y;

        // Jika power-up jatuh ke luar layar, reset posisinya
        if (powerUp->position.y > SCREEN_HEIGHT) {
            InitializePowerUp(powerUp);
        }
    }
}

// Fungsi untuk menggambar power-up
void DrawPowerUp(PowerUp powerUp) {
    if (powerUp.active) {
        DrawTexture(powerUpTexture, (int)powerUp.position.x, (int)powerUp.position.y, WHITE);
    }
}
