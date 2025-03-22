#include "Billy.c"
#include "Chinta.c"
#include "Hanif.c"
#include "Zahwa.c"
#include "Hanif1.c"
#include "Hanif3.c"
#include "raylib.h"
#include "Konfigurasi.h"

int main() {
    displayMenuWithGraphics();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);

    // Inisialisasi game state
    GameState gameState = LEVEL_SELECTION;

    // Inisialisasi objek game
    Paddle paddle;
    Ball ball;
    Level level = {1, EASY}; // Default Level 1, Easy
    ScreenControl screen = {0, PLAY}; // Index menu pause, default ke PLAY
    Lives lives;

    while (!WindowShouldClose()) {
        if (gameState == MENU) {

        }
        else if (gameState == INFO) {

        }
        else if (gameState == SETTINGS) {

        }
        if (gameState == LEVEL_SELECTION) {
            handleLevelSelectionInput(&gameState, &level, &ball);
        }
        else if (gameState == LOADING) {
            setSpeedBall(&level, &ball);
            currentLevel = numberLevel(&level);
            inisialisasiBalok();
            InitPaddle(&paddle, (Vector2){SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 70}, (Vector2){100, 20}, 20);
            initBall(&ball, ball.Speed, &paddle);
            inisialisasibacksound();
            InitLives(&lives, (Vector2){0, 0});
            gameState = PLAY;
        }
        else if (gameState == PLAY) {
            if (IsKeyPressed(KEY_P)) {
                gameState = PAUSE;
            }
            UpdateLives(&lives, &ball);
            updateBall(&ball, &paddle, ball.Speed);
            UpdatePaddle(&paddle);
            bolaterkenabalok(&ball);
            if (AreAllBricksDestroyed()) {
                gameState = LEVEL_SELECTION;
            }
        }
        else if (gameState == PAUSE) {
            HandlePauseInput(&screen); // Navigasi menu pause
            if (IsKeyPressed(KEY_ENTER)) {
                gameState = screen.gameState;
            }
        }
        else if (gameState == GAME_OVER) {

        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (gameState == LEVEL_SELECTION) {
            drawLevel(&level);
        }
        else if (gameState == PLAY) {
            DrawLives(&lives);
            gambarBalok();
            drawBall(ball);
            DrawPaddle(paddle);
        }
        else if (gameState == PAUSE) {
            DrawPauseScreen(&screen);
        }
        EndDrawing();
    }
    tutupbacksound();
    CloseWindow();
    return 0;
}