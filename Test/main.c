#include "raylib.h"
#include "Faridha.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

int main() {
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("Hello World!", 20, 20, 20, RAYWHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
