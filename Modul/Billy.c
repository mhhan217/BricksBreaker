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
}

void panggilbacksound(){
    PlaySound(suaratabrakan);
}

void tutupbacksound() {
    UnloadSound(suaratabrakan);
    CloseAudioDevice();
}

void inisialisasibacksound1(){
    InitAudioDevice();
    suaramenu = LoadSound("suaramenu.wav");
}

void panggilbacksound1(){
    PlaySound(suaramenu);
}

void tutupbacksound1(){
    UnloadSound(suaramenu);
    CloseAudioDevice();
}

void AddBrick(address *head, Rectangle rect, int type) {
    address newNode = (address)malloc(sizeof(Bricks));
    newNode->kotak = rect;
    newNode->on = true;
    newNode->type = type;
    newNode->next = *head;
    *head = newNode;
}

void inisialisasiBalok() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 1; j < BRICK_COLS; j++) {
            Rectangle r;
            r.x = j * (BRICK_WIDTH + BRICK_PADDING) + 50;
            r.y = i * (BRICK_HEIGHT + BRICK_PADDING) + 50;
            r.width = BRICK_WIDTH;
            r.height = BRICK_HEIGHT;
            
            // Level 1 (sementara) //
            // AddBrick(&headBricks, r, 1);

            // Level 2 (sementara) //
            if (j % 2 == 1){
                AddBrick(&headBricks, r, 1);
            }  else if (j % 2 == 0) {
                AddBrick(&headBricks, r, 0);
            }


        }
    }   
}

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

void bolaterkenabalok(Ball* Ball) {
    address current = headBricks;
    while (current != NULL) {
        if (!current->on) {
            current = current->next;
            continue;
        }

        if (Ball->Position.x + Ball->Radius >= current->kotak.x &&
            Ball->Position.x <= current->kotak.x + BRICK_WIDTH &&
            Ball->Position.y + Ball->Radius >= current->kotak.y &&
            Ball->Position.y <= current->kotak.y + BRICK_HEIGHT) {
            current->on = false;    
            panggilbacksound();
            Ball->Speed.y = -Ball->Speed.y;
            return;
        }

        current = current->next;
    }
}

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