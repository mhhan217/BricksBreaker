#include <stdio.h>
#include "raylib.h"
#include "Zidan.h"
#include <time.h>
#include <stdlib.h>


int brickPattern[ROWS][COLS];
void InitializeBricks(Brick bricks[ROWS][COLS]) {
    int paddingX = 2;  
    int paddingY = 2;  
    float brickWidth = 9;  
    float brickHeight = 9;

    int screenWidth = 600;
    int screenHeight = 800;

    int totalWidth = COLS * (brickWidth + paddingX) - paddingX;
    int totalHeight = ROWS * (brickHeight + paddingY) - paddingY;
    int startX = (screenWidth - totalWidth) / 2;  
    int startY = ((screenHeight - totalHeight) / 2) - 150;  

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bricks[i][j].kotak.x = startX + j * (brickWidth + paddingX);
            bricks[i][j].kotak.y = startY + i * (brickHeight + paddingY);
            bricks[i][j].kotak.width = brickWidth;
            bricks[i][j].kotak.height = brickHeight;
            int tipebalok = levels[currentLevel].brickPattern[i][j];
            if (tipebalok == 1)
            {
                bricks[i][j].on = true;
                // bricks[i][j].color = BLUE;
            } else if (tipebalok == 2)
            {
                bricks[i][j].on = true;
                // bricks[i][j].color = RED;
            } else {
                bricks[i][j].on = false;
            }
        }
    }
}


Color WarnaAcak() {
    Color warna[] = {BLUE, GRAY};
    return warna[rand() % 2];
}

void LoadLevel(int NumberLevel, Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int tipebalok = levels[NumberLevel].brickPattern[i][j];
            if (tipebalok == 1) {
                bricks[i][j].isActive = true;
                bricks[i][j].color = BLUE;
            } else {
                bricks[i][j].isActive = false;
            }
        }
    }
}



void UpdateBricks(Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!bricks[i][j].isActive) {
                bricks[i][j].color.a = 0;
            }
        }
    }
}

void DrawBricks(Brick bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bricks[i][j].isActive) {
                Color brickColor = (bricks[i][j].isIndestructible) ? GRAY : BLUE;
                DrawRectangleRec(bricks[i][j].kotak, brickColor);
                bricks[0][0].isIndestructible = true;  
            }
        }
    }
}





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
    InitializeBricks(bricks);

    while (!WindowShouldClose()) {
        switch (gameState) {
            case LEVEL_SELECTION:
                handleLevelSelectionInput(&gameState, &level, &ball);
                break;
            case LOADING:
                setSpeedBall(&level, &ball);
                currentLevel = numberLevel(&level);
                InitializeBricks(bricks);
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
