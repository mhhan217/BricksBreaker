#include "raylib.h"

#include "../Modul/Zahwa.c"
#include "../Include/Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BricksBreaker");

    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 50 }, (Vector2){ 80, 10 }, 0.5f);


    Lives lives;
    InitLives(&lives, (Vector2){0, 0}, 3);

    while (!WindowShouldClose()) {
        UpdatePaddle(&paddle);
        
        UpdateLives(&lives, &ball);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawPaddle(paddle);
        
        DrawLives(&lives);

        EndDrawing();
    }

    UnloadLives(&lives);
    CloseWindow();

    return 0;
}
