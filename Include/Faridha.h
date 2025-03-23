#ifndef FARIDHA_H
#define FARIDHA_H

#include "Konfigurasi.h"

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
