#include <stdio.h>
#include "raylib.h"
#include "Zidan.h"
#include <time.h>
#include <stdlib.h>


int brickPattern[ROWS][COLS];

void InitializeBricks(Brick bricks[ROWS][COLS]) {
    int paddingX = 2;  
    int paddingY = 2;  
    float brickWidth = 9;  
    float brickHeight = 9;

    int screenWidth = 600;
    int screenHeight = 800;

    int totalWidth = COLS * (brickWidth + paddingX) - paddingX;
    int totalHeight = ROWS * (brickHeight + paddingY) - paddingY;
    int startX = (screenWidth - totalWidth) / 2;  
    int startY = ((screenHeight - totalHeight) / 2) - 150;  

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bricks[i][j].kotak.x = startX + j * (brickWidth + paddingX);
            bricks[i][j].kotak.y = startY + i * (brickHeight + paddingY);
            bricks[i][j].kotak.width = brickWidth;
            bricks[i][j].kotak.height = brickHeight;
            bricks[i][j].isActive = true;
            bricks[i][j].color = (brickPattern[i][j] == 1) ? GRAY : BLUE;
            if (i < 2) {  
                bricks[i][j].isIndestructible = true;
                bricks[i][j].color = GRAY;
            } else {
                bricks[i][j].isIndestructible = false;
                bricks[i][j].color = BLUE;
            }
        }
    }
}


Color WarnaAcak() {
    Color warna[] = {BLUE, GRAY};
    return warna[rand() % 2];
}

void LoadLevel(int level, Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bricks[i][j].isActive = true;

            if (level % 2 == 0 && i % 2 == 0) {
                bricks[i][j].isIndestructible = true; 
                bricks[i][j].color = GRAY; 
            } else {
                bricks[i][j].isIndestructible = false;
            }
        }
    }
}


void UpdateBricks(Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!bricks[i][j].isActive) {
                bricks[i][j].color.a = 0;
            }
        }
        return;
    }
}

void DrawBricks(Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bricks[i][j].isActive) {
                Color brickColor = (bricks[i][j].isIndestructible) ? GRAY : BLUE;
                DrawRectangleRec(bricks[i][j].kotak, brickColor);
                bricks[0][0].isIndestructible = true;  

            }
        }
    }
}



void GeneratePattern() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i % 4 == 0) {
                brickPattern[i][j] = 1; 
            } else {
                brickPattern[i][j] = 0; 
            }
        }
    }
}

int main() {
    const int screenWidth = 600;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Breakout Game");
    SetTargetFPS(60);

    srand(time(NULL));

    Brick bricks[ROWS][COLS];
    GeneratePattern();
    InitializeBricks(bricks);
    LoadLevel(1, bricks);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawBricks(bricks);

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
