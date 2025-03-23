#ifndef BILLY_H
#define BILLY_H
#include "konfigurasi.h"

void inisialisasiBalok();
void gambarBalok();
void bolaterkenabalok(Ball *ball);
bool AreAllBricksDestroyed();
void NextLevel();
void inisialisasibacksound();
void panggilbacksound();
void tutupbacksound();
#endif // BILLY_H