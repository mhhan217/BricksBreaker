#include "Billy.c"
#include "Hanif.c"
#include "Zahwa.c"
#include "Hanif1.c"
#include "Hanif3.c"
#include "raylib.h"
#include "Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    // Inisialisasi game state
    GameState gameState = LEVEL_SELECTION;

    // Inisialisasi objek game
    Paddle paddle;
    Ball ball;
    Level level = {1, EASY}; // Default Level 1, Easy
    int menuIndex = 0;  // Menyimpan posisi menu yang dipilih
    ScreenControl screen;

    // Inisialisasi Paddle dan Ball
    InitPaddle(&paddle, (Vector2){SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 70},
               (Vector2){100, 20}, 20);
    setSpeedBall(&level, &ball); 
    initBall(&ball, ball.Speed, &paddle);
    inisialisasibacksound();
    inisialisasiBalok();

    while (!WindowShouldClose()) {
        switch (gameState) {
            case LEVEL_SELECTION:
                handleLevelSelectionInput(&gameState, &level, &ball);
                break;
            case LOADING:
                setSpeedBall(&level, &ball);
                currentLevel = numberLevel(&level);
                inisialisasiBalok();
                gameState = PLAY;
                break;
            case PLAY:
                if (IsKeyPressed(KEY_P)) {
                    gameState = PAUSE;
                } else {
                    updateBall(&ball, &paddle, ball.Speed);
                    UpdatePaddle(&paddle);
                    bolaterkenabalok(&ball); // Cek apakah bola mengenai bricks
    
                    if (AreAllBricksDestroyed()) {
                        gameState = LEVEL_SELECTION; // Kembali ke pemilihan level jika semua bricks hancur
                    }
                }
                break;
            case PAUSE:
                HandlePauseInput(&screen);
                if (screen.gameState != PAUSE) {
                    gameState = screen.gameState; // Kembali ke state lain jika ada perubahan
                }
                break;
            case MENU:
                gameState = LEVEL_SELECTION; // Kembali ke pemilihan level
                break;
            case EXIT:
                CloseWindow();
                return 0;
        }
    
        // Rendering game
        BeginDrawing();
        ClearBackground(BLACK);
    
        switch (gameState) {
            case LEVEL_SELECTION:
                drawLevel(&level);
                break;
            case PLAY:
                gambarBalok();  // Tambahkan bricks ke layar
                drawBall(ball);
                DrawPaddle(paddle);
                break;
            case PAUSE:
                DrawPauseScreen(&screen);
                break;
        }
    
        EndDrawing();
    }
    tutupbacksound();
    CloseWindow();
    return 0;
}