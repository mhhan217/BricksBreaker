#include <stdio.h>
#include "../Include/Billy.h"
#include "../Include/Hanif.h"
#include "../Include/Zidan.h"
#include "../Include/Konfigurasi.h"
#include <math.h>

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
            int tipebalok = level.brickPattern[i][j];
            if (tipebalok == 1 || tipebalok == 2) {
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
                int tipebalok = level.brickPattern[i][j];
                if (tipebalok == 1) {
                    DrawRectangleRec(bricks[i][j].kotak, BLUE);
                } else if (tipebalok == 2) {
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
                    if (level.brickPattern[i][j] == 1 || level.brickPattern[i][j] == 2) {
                        if (level.brickPattern[i][j] == 1) {
                            brick->on = false;
                        }
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

void SetDifficulty(Difficulty difficulty) {
    level.DifficultLevel = difficulty;
    inisialisasiBalok();
}

void NextLevel() {
    level.NumberLevel = (level.NumberLevel + 1) % TOTAL_LEVELS;
    inisialisasiBalok();
}
