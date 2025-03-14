#include <stdio.h>
#include "Billy.h"
#include "Hanif.h"
#include "Hanif.h"
#include <math.h>

int currentDifficulty = 0;
int currentLevel = 0;
Sound suaratabrakan;

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
            bricks[i][j].on = levelPatterns[currentDifficulty][currentLevel][i][j] == 1;
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
                DrawRectangleRec(bricks[i][j].kotak, BLUE);
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
            if (Ball->Posisi.x + Ball->Radius >= brick->kotak.x && 
                Ball->Posisi.x <= brick->kotak.x + BRICK_WIDTH &&
                Ball->Posisi.y + Ball->Radius >= brick->kotak.y && 
                Ball->Posisi.y <= brick->kotak.y + BRICK_HEIGHT) {
                    brick->on = false;
                    panggilbacksound();
                    Ball->Kecepatan.y = -Ball->Kecepatan.y;
                    return;
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
        currentLevel = 0;
        inisialisasiBalok();
    }
}

void NextLevel() {
    if (currentLevel < LEVELS_PER_DIFFICULTY - 1) {
        currentLevel++;
    } else {
        currentLevel = 0;
        if (currentDifficulty < DIFFICULTY_LEVELS - 1) {
            currentDifficulty++;
        } else {
            currentDifficulty = 0;
        }
    }
    inisialisasiBalok();
}