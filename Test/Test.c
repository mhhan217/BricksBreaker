#include "zahwa.h"
#include "konfigurasi.h"
#include "raylib.h"
#include "zahwa.c"

int main() {
    
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "Bricks Breaker");
    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 50 }, (Vector2){ 100, 20 }, 5.0f);
    SetTargetFPS(60); 

    while (!WindowShouldClose()) {
        UpdatePaddle(&paddle);
        ClearBackground(BLACK);
        DrawPaddle(paddle);
        EndDrawing();
    }

}
