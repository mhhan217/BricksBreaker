//Faridha.h

#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

#define MAX_POWERUPS 5

// Deklarasi variabel global
extern int gameState;
extern Texture2D powerUpTextures[3];

typedef struct {
    char pesan[20];  
    int indeksMenu;
    Color warnaTeks;
} LayarGameOver;

// Struktur dan enum
typedef enum {
    POWER_EXTRA_LIFE, 
    POWER_EXTRA_BALL,
    POWER_ENLARGE_PADDLE
} PowerUpType;

typedef struct PowerUp {
    Vector2 posisi;
    Vector2 kecepatan;
    int radius;
    int tipe;
    bool aktif;
    float durasi;
    float waktu;
} PowerUp;

// typedef struct Ball {
//     float x;
//     float y;
//     float radius;
//     float speedX;
//     float speedY;
//     bool isStrong;      // Menandai apakah bola sedang kuat
//     float strongTime;   // Durasi efek kuat
// } Ball;

typedef struct {
    Rectangle rect;
    bool isDestroyed;
} Balok;

// Deklarasi fungsi
void InisialisasiLayarGameOver(LayarGameOver *layar);
void DrawGameOverScreen(ScreenControl *screen);
void HandleGameOverInput(ScreenControl *screen);
void HapusLayarGameOver(LayarGameOver *layar);
void PauseGame();
void ResumeGame();
void BackToMenu();
void ShowGameOver();

// PowerUp
void LoadPowerUpTextures();
void InitializePowerUp(PowerUp *powerUp);
void UpdatePowerUp(PowerUp *powerUp, float deltaTime);
void DrawPowerUp(PowerUp powerUp);
void CloseGame();
void DestroyBricksAround(Balok brick); 
#endif