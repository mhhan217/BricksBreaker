#ifndef BILLY_H
#define BILLY_H
#include "Konfigurasi.h"
#include "raylib.h"
#include "Hanif.h"

#define DIFFICULTY_LEVELS 3
#define BRICK_WIDTH 10
#define BRICK_HEIGHT 10
#define BRICK_PADDING 5
#define TOTAL_LEVELS 30

// int currentLevel;

void inisialisasiBalok();
void gambarBalok();
void bolaterkenabalok(Ball *ball);
bool AreAllBricksDestroyed();
void NextLevel();
void inisialisasibacksound();
void panggilbacksound();
void tutupbacksound();
void inisialisasibacksound1();
void panggilbacksound1();
void tutupbacksound1();

typedef struct Bricks *address;
typedef struct Bricks {
    Rectangle kotak;
    bool on;
    address next;
} Bricks;
void AddBrick(address *head, Rectangle rect);

#endif // BILLY_H