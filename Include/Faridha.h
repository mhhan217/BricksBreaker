#ifndef FARIDHA_H
#define FARIDHA_H

#include "raylib.h"
#include "Konfigurasi.h"

extern int gameState;

typedef struct {
    char pesan[20];  
    int indeksMenu;
    Color warnaTeks;
} LayarGameOver;

typedef enum { 
    POWER_NONE,          
    POWER_ENLARGE_PADDLE, 
    POWER_SHRINK_PADDLE,  
    POWER_SPEED_UP_BALL,  
    POWER_SLOW_DOWN_BALL, 
    POWER_EXTRA_LIFE      
} PowerUpType;

typedef struct PowerUp {
    Vector2 position;
    Vector2 speed;
    int radius;
    int type;
    bool active;
} PowerUp;

extern Texture2D powerUpTexture;


void InisialisasiLayarGameOver(LayarGameOver *layar);
void DrawGameOverScreen(ScreenControl *screen);
void HandleGameOverInput(ScreenControl *screen);
void HapusLayarGameOver(LayarGameOver *layar);
void PauseGame();
void ResumeGame();
void BackToMenu();
void ShowGameOver();

//PowerUp
void InitializePowerUp(PowerUp *powerUp);
void UpdatePowerUp(PowerUp *powerUp);
void DrawPowerUp(PowerUp powerUp);


#endif
