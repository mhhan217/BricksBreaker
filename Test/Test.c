#include <raylib.h> 
#include "../Include/Faridha.h"

extern GameState* gameState;
extern LayarGameOver* layar;
extern int currentIndex;

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Over Screen");
    SetTargetFPS(60);

    // Inisialisasi GameState
    GameState currentGameState = GAME_OVER;
    gameState = &currentGameState;
    
    // Inisialisasi LayarGameOver
    LayarGameOver layarGameOver;
    layar = &layarGameOver;
    
    // Reset currentIndex
    currentIndex = 0;

    InisialisasiLayarGameOver(&layarGameOver);

    while (!WindowShouldClose()) {
        HandleGameOverInput(gameState);
        DrawGameOverScreen(gameState);
        
        // Jika state berubah dari Game Over, keluar dari loop
        if (*gameState != GAME_OVER) {
            break;
        }
    }

    HapusLayarGameOver(&layarGameOver);
    CloseWindow();

    return 0;
}