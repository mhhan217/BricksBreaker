#include "raylib.h"
#include "Faridha.h"

int main() {
    InitWindow(LEBAR_LAYAR, TINGGI_LAYAR, "Layar Game Over");
    SetTargetFPS(60);
    
    LayarGameOver layarGameOver;
    InisialisasiLayarGameOver(&layarGameOver);

    while (!WindowShouldClose()) {
        GambarLayarGameOver(layarGameOver);
    }

    HapusLayarGameOver(&layarGameOver);
    CloseWindow();
    return 0;
}
