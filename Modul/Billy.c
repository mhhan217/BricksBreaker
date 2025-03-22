#include <stdio.h>
#include "Billy.h"
#include "Hanif.h"
#include "Zidan.h"
#include <math.h>

bool isPaused = false;
int currentDifficulty = 0;
Sound suaratabrakan;
Level level;
void inisialisasibacksound() {
    InitAudioDevice();
    suaratabrakan = LoadSound("tabrakan.wav");
}

void panggilbacksound(){
    PlaySound(suaratabrakan);
}

void tutupbacksound() {
    UnloadSound(suaratabrakan);
    CloseAudioDevice();
}

void inisialisasiBalok() {
    int i=0;
    while (i < BRICK_ROWS) {
        int j=0;
        while (j < BRICK_COLS){
            bricks[i][j].kotak.x = j * (BRICK_WIDTH + BRICK_PADDING) + 38;
            bricks[i][j].kotak.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 38;
            bricks[i][j].kotak.width = BRICK_WIDTH;
            bricks[i][j].kotak.height = BRICK_HEIGHT;
            int tipebalok = levels[currentLevel].brickPattern[i][j];
            if (tipebalok == 1)
            {
                bricks[i][j].on = true;
            } else if (tipebalok == 2)
            {
                bricks[i][j].on = true;
            } else {
                bricks[i][j].on = false;
            }
            j++;
        }
        i++; 
    }    
}

void gambarBalok() {
    int i=0;
    while (i < BRICK_ROWS) {
        int j=0;
        while (j < BRICK_COLS){
            if (bricks[i][j].on) {
                int tipebalok = levels[currentLevel].brickPattern[i][j];
                if (tipebalok == 1)
                {
                    DrawRectangleRec(bricks[i][j].kotak, BLUE);
                } else if (tipebalok == 2)
                {
                    DrawRectangleRec(bricks[i][j].kotak, DARKGRAY);
                }
            }
            j++;
        }
        i++; 
    }
}

void bolaterkenabalok(Ball* Ball) {
    int i = 0;
    while (i < BRICK_ROWS) {
        int j = 0;
        while (j < BRICK_COLS) {
            Brick *brick = &bricks[i][j];
            if (!brick->on) {  
                j++;  
                continue;
            }
            if (Ball->Position.x + Ball->Radius >= brick->kotak.x && 
                Ball->Position.x <= brick->kotak.x + BRICK_WIDTH &&
                Ball->Position.y + Ball->Radius >= brick->kotak.y && 
                Ball->Position.y <= brick->kotak.y + BRICK_HEIGHT) {
                    if (levels[currentLevel].brickPattern[i][j] == 1)
                    {
                        brick->on = false;
                        panggilbacksound();
                        Ball->Speed.y = -Ball->Speed.y;
                        return;
                    } else if (levels[currentLevel].brickPattern[i][j] == 2)
                    {
                        panggilbacksound();
                        Ball->Speed.y = -Ball->Speed.y;
                        return;
                    }
                    
            }
            j++;
        }
        i++;
    }
}

bool AreAllBricksDestroyed() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].on) return false;
        }
    }
    return true;
}

void SetDifficulty(int difficulty) {
    if (difficulty >= 0 && difficulty < DIFFICULTY_LEVELS) {
        currentDifficulty = difficulty; 
        inisialisasiBalok(); 
    }
}


void NextLevel() {
    currentLevel = (currentLevel + 1) % TOTAL_LEVELS;  
    inisialisasiBalok();
}


int inisialisasiGame(){
    if (IsKeyPressed(KEY_P)) {
        isPaused = !isPaused;
    }
    inisialisasibacksound();
    Ball bola;
    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 15.0f);
    initBall(&bola, (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, &paddle);
    inisialisasiBalok();

    while (!WindowShouldClose()) {
        if (!isPaused)
        {
            bolaterkenabalok(&bola);
            updateBall(&bola, &paddle, (Vector2){0, -20});
            UpdatePaddle(&paddle);
            if (AreAllBricksDestroyed()) {
                NextLevel();
            }
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        gambarBalok();
        drawBall(bola);
        DrawPaddle(paddle);
        if (isPaused) {
            DrawText("PAUSED", SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, 40, RED);
            DrawText("Tekan 'P' untuk melanjutkan", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 50, 20, WHITE);
        }
        EndDrawing();
    }
    tutupbacksound();
    return 0;
}