#include <stdio.h>
#include "Billy.h"
#include "Zidan.h"
#include "Hanif.h"
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
                bricks[i][j].warna = BLUE;
            } else if (tipebalok == 2)
            {
                bricks[i][j].on = true;
                bricks[i][j].warna = RED;
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
            Balok *brick = &bricks[i][j];
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
    currentLevel = (currentLevel + 1) % TOTAL_LEVELS;  // Looping dari 1-10
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

void ShowMenu() {
    int selectedDifficulty = 0;
    int selectedLevel = 0;

    while (!WindowShouldClose()) {
        // Navigasi Kesulitan (Easy, Medium, Hard)
        if (IsKeyPressed(KEY_DOWN)) selectedDifficulty = (selectedDifficulty + 1) % DIFFICULTY_LEVELS;
        if (IsKeyPressed(KEY_UP)) selectedDifficulty = (selectedDifficulty - 1 + DIFFICULTY_LEVELS) % DIFFICULTY_LEVELS;

        // Navigasi Level (1 - 10)
        if (IsKeyPressed(KEY_RIGHT)) selectedLevel = (selectedLevel + 1) % TOTAL_LEVELS;
        if (IsKeyPressed(KEY_LEFT)) selectedLevel = (selectedLevel - 1 + TOTAL_LEVELS) % TOTAL_LEVELS;

        BeginDrawing();
        ClearBackground(BLACK);

        // Tampilkan opsi kesulitan
        DrawText("Pilih Kesulitan:", 300, 150, 30, WHITE);
        DrawText(selectedDifficulty == 0 ? "> Easy" : "  Easy", 350, 200, 25, selectedDifficulty == 0 ? YELLOW : WHITE);
        DrawText(selectedDifficulty == 1 ? "> Medium" : "  Medium", 350, 230, 25, selectedDifficulty == 1 ? YELLOW : WHITE);
        DrawText(selectedDifficulty == 2 ? "> Hard" : "  Hard", 350, 260, 25, selectedDifficulty == 2 ? YELLOW : WHITE);

        // Tampilkan opsi level
        DrawText("Pilih Level:", 300, 320, 30, WHITE);
        DrawText(TextFormat("> Level %d", selectedLevel + 1), 350, 370, 25, YELLOW);

        // Petunjuk kontrol
        DrawText("Gunakan ARROW KEYS untuk memilih", 200, 450, 20, LIGHTGRAY);
        DrawText("Tekan ENTER untuk memulai", 250, 500, 20, GREEN);

        EndDrawing();

        // Konfirmasi pemilihan level & kesulitan
        if (IsKeyPressed(KEY_ENTER)) {
            SetDifficulty(selectedDifficulty); // Atur kecepatan bola
            currentLevel = selectedLevel; // Tetapkan level yang dipilih
            inisialisasiBalok(); // Pastikan bricks diinisialisasi sesuai level
            inisialisasiGame(); // Masuk ke game
        }
    }
}