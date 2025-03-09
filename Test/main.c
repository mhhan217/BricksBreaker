#include "raylib.h"
#include "Faridha.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Layar Game Over");
    SetTargetFPS(60);
    
    LayarGameOver layarGameOver;
    InisialisasiLayarGameOver(&layarGameOver);

    while (!WindowShouldClose()) {
        if (gameState == 0) {
            GambarLayarGameOver(layarGameOver);
        } else if (gameState == 1) {
            GambarLayarScore();
        } else if (gameState == 2) {
        } else if (gameState == 3) {
        }
    }

    HapusLayarGameOver(&layarGameOver);
    CloseWindow();
    return 0;
}
