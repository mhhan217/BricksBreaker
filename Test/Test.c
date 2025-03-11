#include "raylib.h"
#include "../Include/Hanif.h"
#include "../Include/Zahwa.h"
#include "../Include/Konfigurasi.h"

int main() {
    // Inisialisasi window
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
    setSpeedBall(&level, &ball); // Set kecepatan bola berdasarkan level
    initBall(&ball, ball.Speed, &paddle); // Gunakan kecepatan bola yang telah di-set

    // Loop utama
    while (!WindowShouldClose()) {
        // Handle input berdasarkan state game
        if (gameState == LEVEL_SELECTION) {
            handleLevelSelectionInput(&gameState, &level, &ball);
            drawLevel(&level);
        }
        else if (gameState == LOADING) {
            setSpeedBall(&ball,&level); // Pastikan kecepatan bola diperbarui
            gameState = PLAY;  // Masuk ke mode bermain
        }
        else if (gameState == PLAY) {
            if (IsKeyDown(KEY_P)) {
                gameState = PAUSE;
            }else {
                updateBall(&ball, &paddle, ball.Speed);
                UpdatePaddle(&paddle);
            }
        }else if (gameState == PAUSE) {
            HandlePauseInput(&screen);
            if (screen.gameState != PAUSE) {
                gameState = screen.gameState; // Kembali ke state lain jika ada perubahan
            }
        }

        // Render tampilan game
        BeginDrawing();
        ClearBackground(BLACK);

        if (gameState == LEVEL_SELECTION) {
            drawLevel(&level); // Gunakan menuIndex yang dinamis
        }
        else if (gameState == PLAY) {
            drawBall(ball);
            DrawPaddle(paddle);
        }else if (gameState == PAUSE) {
            DrawPauseScreen(&screen);
        }


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
