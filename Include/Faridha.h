#ifndef FARIDHA_H
#define FARIDHA_H

#include "Konfigurasi.h"
void displayGameOver(ScreenControl *screen);
void PauseGame();
void ResumeGame();
void BackToMenu();
void ShowGameOver();

//PowerUp
void InitializePowerUp(PowerUp *powerUp);
void UpdatePowerUp(PowerUp *powerUp);
void DrawPowerUp(PowerUp powerUp);


#endif
