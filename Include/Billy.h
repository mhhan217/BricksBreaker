#ifndef BILLY_H
#define BILLY_H
#include "konfigurasi.h"

#define DIFFICULTY_LEVELS 3
#define BRICK_WIDTH 10
#define BRICK_HEIGHT 10
#define BRICK_PADDING 5
#define TOTAL_LEVELS 30

int currentLevel;

void inisialisasiBalok();
void gambarBalok();
void bolaterkenabalok(Ball *ball);
bool AreAllBricksDestroyed();
void NextLevel();
void inisialisasibacksound();
void panggilbacksound();
void tutupbacksound();
#endif // BILLY_H