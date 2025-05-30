#include "../Modul/Billy.c"
#include "../Modul/Chinta.c"
#include "../Modul/Hanif.c"
#include "../Modul/Zahwa.c"
#include "../Modul/Hanif1.c"
#include "../Modul/Hanif3.c"
#include "../Modul/Faridha.c"
#include "../Modul/Zidan.c"
#include "raylib.h"
#include "../Include/Konfigurasi.h"

int main() {
    inisialisasibacksound();
    displayMenuWithGraphics();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);
    GameState gameState = LEVEL_SELECTION;
    Paddle paddle;
    Ball ball;
    Level level = {1, EASY};
    Lives lives;
    LayarGameOver *layar = malloc(sizeof(LayarGameOver));

    InisialisasiLayarGameOver(layar);
    setSpeedBall(&level, &ball);
    int currentLevel = numberLevel(&level);
    inisialisasiBalok(currentLevel);
    InitPaddle(&paddle, (Vector2){SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 70}, (Vector2){100, 20}, 20);
    initBall(&ball, ball.Speed, &paddle);
    InitLives(&lives, (Vector2){0, 0});

    while (!WindowShouldClose()) {
        if (gameState == MENU) {
            displayMenuWithGraphics();
        }
        else if (gameState == INFO) {
            displayInfo();
        }
        else if (gameState == SETTINGS) {
            displaySettings();
        }
        if (gameState == LEVEL_SELECTION) {
            handleLevelSelectionInput(&gameState, &level, &ball);
        }
        else if (gameState == RESTART) {
            inisialisasiBalok(currentLevel);
            InitPaddle(&paddle, (Vector2){SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 70}, (Vector2){100, 20}, 20);
            initBall(&ball, ball.Speed, &paddle);
            InitLives(&lives, (Vector2){0, 0});
            gameState = PLAY;
        }
        else if (gameState == PLAY) {
            if (IsKeyPressed(KEY_P)) {
                gameState = PAUSE;
            }
            bolaterkenabalok(&ball);            
            UpdateLives(&lives, &ball);
            updateBall(&ball, &paddle, ball.Speed);
            UpdatePaddle(&paddle);
            if (lives.jumlah_nyawa == 0) {
                gameState = GAME_OVER;
            }
            if (AreAllBricksDestroyed()) {
                gameState = LEVEL_SELECTION;
            }
        }

        else if (gameState == PAUSE) {
            HandlePauseInput(&gameState); 
        }

        else if (gameState == GAME_OVER) {
            HandleGameOverInput(&gameState, layar);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if (gameState == MENU){
            displayMenuWithGraphics();
        }
        else if(gameState == INFO){
            displayInfo();
        }
        else if(gameState == SETTINGS){
            displaySettings();
        }
        else if (gameState == LEVEL_SELECTION) {
            displayLevel();
        }
        else if (gameState == PLAY) {
            DrawLives(&lives);
            gambarBalok();
            drawBall(&ball);
            DrawPaddle(paddle);
        }
        else if (gameState == PAUSE) {
            DrawPauseScreen(&gameState);
        }
        else if (gameState == GAME_OVER) {
            DrawGameOverScreen(&gameState, layar);
        }

        EndDrawing();
    }

    HapusLayarGameOver(layar);
    FreeAllBricks();
    tutupbacksound();
    CloseWindow();
    return 0;
}