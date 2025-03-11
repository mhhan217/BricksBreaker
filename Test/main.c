#include "raylib.h"
#include "Faridha.h"
#include "Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Layar Game Over");
    SetTargetFPS(TARGET_FPS);

    ScreenControl screenControl = {GAME_OVER, 0};
    LayarGameOver layarGameOver;
    InisialisasiLayarGameOver(&layarGameOver);

    while (!WindowShouldClose()) {
        switch (screenControl.gameState) {
            case GAME_OVER:
                HandleGameOverInput(&screenControl);
                DrawGameOverScreen(&screenControl);  
                break;
            
            case MENU:
                break;
            
            case PLAYING:
                break;
            
            case EXIT:
                CloseWindow();
                return 0; 
                break;
            
            default:
                break;
        }
    }

    HapusLayarGameOver(&layarGameOver);
    CloseWindow();
    return 0;
}
