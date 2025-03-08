//
// Created by Chinta on 2/23/2025.
//
#include "raylib.h"
#include "Chinta.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker Menu");
    SetTargetFPS(60);

    displayMenuWithGraphics();  

    CloseWindow();
    return 0;
}
