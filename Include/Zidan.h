#ifndef ZIDAN_H
#define ZIDAN_H

#include "Konfigurasi.h"

#define BRICK_LEBAR 3
#define BRICK_TINGGI 3

#define ROWS 30
#define COLS 54

typedef struct {
    Vector2 position;
    Rectangle kotak;
    float width;
    float heigth;
    Color color;        
    bool isActive;      
    bool isIndestructible;  
} Brick;

void InitializeBricks(Brick bricks[ROWS][COLS]);
void LoadLevel(int level, Brick bricks[ROWS][COLS]);
void UpdateBricks(Brick bricks[ROWS][COLS]);
void DrawBricks(Brick bricks[ROWS][COLS]);
void GeneratePattern();

#endif

