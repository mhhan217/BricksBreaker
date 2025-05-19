#include <stdio.h>
#include "raylib.h"
#include "../Include/Zidan.h"
#include <time.h>
#include <stdlib.h>


int brickPattern[BRICK_ROWS][BRICK_COLS];
void InitializeBricks(Brick bricks[BRICK_ROWS][BRICK_ROWS]) {
    int paddingX = 2;  
    int paddingY = 2;  
    float brickWidth = 9;  
    float brickHeight = 9;

    int screenWidth = 600;
    int screenHeight = 800;

    int totalWidth = BRICK_COLS * (brickWidth + paddingX) - paddingX;
    int totalHeight = BRICK_ROWS * (brickHeight + paddingY) - paddingY;
    int startX = (screenWidth - totalWidth) / 2;  
    int startY = ((screenHeight - totalHeight) / 2) - 150;  

    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].kotak.x = startX + j * (brickWidth + paddingX);
            bricks[i][j].kotak.y = startY + i * (brickHeight + paddingY);
            bricks[i][j].kotak.width = brickWidth;
            bricks[i][j].kotak.height = brickHeight;
            int tipebalok = levels[currentLevel].brickPattern[i][j];
            if (tipebalok == 1)
            {
                bricks[i][j].on = true;
                bricks[i][j].color = BLUE;
            } else if (tipebalok == 2)
            {
                bricks[i][j].on = true;
                bricks[i][j].color = RED;
            } else {
                bricks[i][j].on = false;
            }
        }
    }
}


Color WarnaAcak() {
    Color warna[] = {BLUE, GRAY};
    return warna[rand() % 2];
}

void LoadLevel(int level, Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            int tipebalok = levels[currentLevel].brickPattern[i][j];
            if (tipebalok == 1) {
                bricks[i][j].isActive = true;
                bricks[i][j].color = BLUE;
            } else {
                bricks[i][j].isActive = false;
            }
        }
    }
}



void UpdateBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (!bricks[i][j].isActive) {
                bricks[i][j].color.a = 0;
            }
        }
    }
}

void DrawBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].isActive) {
                Color brickColor = (bricks[i][j].isIndestructible) ? GRAY : BLUE;
                DrawRectangleRec(bricks[i][j].kotak, brickColor);
                bricks[0][0].isIndestructible = true;  
            }
        }
    }
}



void GeneratePattern() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (i % 4 == 0) {
                brickPattern[i][j] = 1; 
            } else {
                brickPattern[i][j] = 0; 
            }
        }
    }
}