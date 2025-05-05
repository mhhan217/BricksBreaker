#include <stdio.h>
#include <stdbool.h>
#include "../Include/Konfigurasi.h"
#include "../Include/Chinta.h"
#include "../Include/Faridha.h"
#include "../Include/Hanif.h"
#include "../Include/Zahwa.h"
#include "../Include/Billy.h"
#include "../Include/Zidan.h"

void startGame(ScreenControl *screen) {
    Paddle paddle;
    Ball ball;
    Lives lives;
    Brick bricks[BRICK_ROWS][BRICK_COLS];

    InitPaddle(&paddle, (Vector2){SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30}, (Vector2){100, 10}, 5.0f);
    initBall(&ball, (Vector2){4, -4}, &paddle);
    InitLives(&lives, (Vector2){10, 10}); // Perbaikan jumlah parameter
    LoadLevel(screen->index, bricks);

    while (screen->gameState == PLAY && !WindowShouldClose()) {
        if (IsKeyPressed(KEY_P)) {
            screen->gameState = PAUSE;
            return;
        }

        updateBall(&ball, ball.Speed, &paddle);
        UpdatePaddle(&paddle);
        UpdateBricks(bricks);
        UpdateLives(&lives, &ball);

        if (AreAllBricksDestroyed()) {
            screen->gameState = GAME_OVER;
            return;
        }

        if (lives.jumlah_nyawa <= 0) {
            screen->gameState = GAME_OVER;
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawPaddle(paddle);
        drawBall(&ball);
        DrawBricks(bricks);
        DrawLives(&lives);
        EndDrawing();
    }
}

int main(){
    ScreenControl screen = {MENU, 0};
    bool running = true;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker"); // Tambahkan InitWindow
    SetTargetFPS(60);

    while (running) {
        if (WindowShouldClose()) {
            screen.gameState = EXIT;
        }

        switch (screen.gameState) {
            case MENU:
                displayMenu(&screen);
                break;
            case SETTINGS:
                displaySettings(&screen);
                screen.gameState = MENU;
                break;
            case INFO:
                displayInfo(&screen);
                screen.gameState = MENU;
                break;
            case LEVEL_SELECTION:
                displayLevel(&screen);
                break;
            case LOADING:
                LoadLevel(screen.index, bricks);
                screen.gameState = PLAY;
                break;
            case PLAY:
                startGame(&screen);
                break;
            case PAUSE:
                displayPause(&screen);
                break;
            case GAME_OVER:
                displayGameOver(&screen);
                break;
            case EXIT:
                running = false;
                break;
        }
    }

    CloseWindow();
    return 0;
}
