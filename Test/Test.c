#include "raylib.h"
#include "../Include/Hanif.h"

int main() {
    // Inisialisasi window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);
    Level level;
    // Inisialisasi bola
    Ball ball;
    initBall(&ball,getSpeedBall(&ball),&paddle);

    while (!WindowShouldClose()) {
        updateBall(&ball,&paddle,(Vector2){0,-20});
        UpdatePaddle(&paddle);
        BeginDrawing();
        ClearBackground(BLACK);
        drawBall(ball);
        DrawPaddle(paddle);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
