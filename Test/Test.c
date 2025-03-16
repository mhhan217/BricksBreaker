#include "raylib.h"
#include "../Include/Zahwa.h"
#include "../Include/Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 5.0f);

    Ball ball;
    InitBall(&ball, (Vector2){3, -5}, &paddle);

    Lives lives;
    InitLives(&lives);

    while (!WindowShouldClose()) {
        UpdatePaddle(&paddle);
        UpdateBall(&ball, &paddle, (Vector2){3, -5});

        CekBolaJatuh(&lives, &ball);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawLives(&lives);

        DrawBall(ball);
        DrawPaddle(paddle);

        EndDrawing();
    }

    unloadLives(&lives);
    CloseWindow();
    
    return 0;
}