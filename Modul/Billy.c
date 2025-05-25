#include <stdio.h>
#include <stdlib.h>
#include "../Include/Billy.h"
#include "../Include/Hanif.h"
#include "../Include/Zidan.h"
#include <math.h>

int currentDifficulty = 0;
Sound suaratabrakan, suaramenu;
Level level;
address headBricks = NULL;

void inisialisasibacksound() {
    InitAudioDevice();
    suaratabrakan = LoadSound("tabrakan.wav");
    suaramenu = LoadSound("suaramenu.wav");
}

void panggilbacksound(){
    PlaySound(suaratabrakan);
}

void panggilbacksound1(){
    PlaySound(suaramenu);
}

void tutupbacksound() {
    UnloadSound(suaratabrakan);
    UnloadSound(suaramenu);
    CloseAudioDevice();
}

// void inisialisasiBalok() {
//     int i=0;
//     while (i < BRICK_ROWS) {
//         int j=0;
//         while (j < BRICK_COLS){
//             bricks[i][j].kotak.x = j * (BRICK_WIDTH + BRICK_PADDING) + 38;
//             bricks[i][j].kotak.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 38;
//             bricks[i][j].kotak.width = BRICK_WIDTH;
//             bricks[i][j].kotak.height = BRICK_HEIGHT;
//             int tipebalok = levels[currentLevel].brickPattern[i][j];
//             if (tipebalok == 1)
//             {
//                 bricks[i][j].on = true;
//             } else {
//                 bricks[i][j].on = false;
//             }
//             j++;
//         }
//         i++; 
//     }    
// }

void inisialisasiBalok() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 1; j < BRICK_COLS; j++) {
            Rectangle r;
            r.x = j * (BRICK_WIDTH + BRICK_PADDING) + 50;
            r.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 50;
            r.width = BRICK_WIDTH;
            r.height = BRICK_HEIGHT;
            
            AddBrick(&headBricks, r, 1);
        }
    }   
}

void AddBrick(address *head, Rectangle rect, int type) {
    address newNode = (address)malloc(sizeof(Bricks));
    newNode->kotak = rect;
    newNode->on = true;
    newNode->type = type;
    newNode->next = *head;
    *head = newNode;
}

// void gambarBalok() {
//     int i=0;
//     while (i < BRICK_ROWS) {
//         int j=0;
//         while (j < BRICK_COLS){
//             if (bricks[i][j].on) {
//                 DrawRectangleRec(bricks[i][j].kotak, BLUE);
//             }
//             j++;
//         }
//         i++; 
//     }
// }

void gambarBalok() {
    address current = headBricks;
    while (current != NULL) {
        if (current->on == true){
            if (current -> type == 1)
            {
                DrawRectangleRec(current->kotak, BLUE);   
            }         
        }
        current = current->next;
    }
}

// void bolaterkenabalok(Ball* Ball) {
//     int i = 0;
//     while (i < BRICK_ROWS) {
//         int j = 0;
//         while (j < BRICK_COLS) {
//             Brick *brick = &bricks[i][j];
//             if (!brick->on) {  
//                 j++;  
//                 continue;
//             }
//             if (Ball->Position.x + Ball->Radius >= brick->kotak.x && 
//                 Ball->Position.x <= brick->kotak.x + BRICK_WIDTH &&
//                 Ball->Position.y + Ball->Radius >= brick->kotak.y && 
//                 Ball->Position.y <= brick->kotak.y + BRICK_HEIGHT) {
//                     if (levels[currentLevel].brickPattern[i][j] == 1)
//                     {
//                         brick->on = false;
//                         panggilbacksound();
//                         Ball->Speed.y = -Ball->Speed.y;
//                         return;
//                     } else if (levels[currentLevel].brickPattern[i][j] == 2)
//                     {
//                         panggilbacksound();
//                         Ball->Speed.y = -Ball->Speed.y;
//                         return;
//                     }
                    
//             }
//             j++;
//         }
//         i++;
//     }
// }

void bolaterkenabalok(Ball* Ball) {
    address current = headBricks;
    while (current != NULL) {
        if (!current->on) {
            current = current->next;
            continue;
        }
        if (CheckCollisionCircleRec(Ball->Position, Ball->Radius, current->kotak)) {
            current->on = false;
            panggilbacksound();
            Ball->Speed.y *= -1;
            return;
        }
        current = current->next;
    }
}

// bool AreAllBricksDestroyed() {
//     for (int i = 0; i < BRICK_ROWS; i++) {
//         for (int j = 0; j < BRICK_COLS; j++) {
//             if (bricks[i][j].on) return false;
//         }
//     }
//     return true;
// }

bool AreAllBricksDestroyed() {
    address current = headBricks;
    while (current != NULL) {
        if (current->on) return false;
        current = current->next;
    }
    return true;
}

void FreeAllBricks() {
    address current = headBricks;
    while (current != NULL) {
        address temp = current;
        current = current->next;
        free(temp);
    }
    headBricks = NULL;
}