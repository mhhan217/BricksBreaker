#ifndef CHINTA_H
#define CHINTA_H

#include <stdio.h>
#include "raylib.h"
extern float musicVolume;
extern float soundVolume;
extern Sound ballBounce;
extern Music gameMusic;

// Deklarasi fungsi
void displayMenu(ScreenControl *screen);
void displayLevel(ScreenControl *screen);
void displayInfo(ScreenControl *screen);
void displaySettings(ScreenControl *screen);
void IncreaseVolume();
void DecreaseVolume();
void IncreaseSound();
void DecreaseSound();
void displayPause(ScreenControl *screen);

#endif // CHINTA_H