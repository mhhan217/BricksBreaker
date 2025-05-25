#include <stdio.h>
#include "raylib.h"
#include "../Include/Zidan.h"
#include <time.h>
#include <stdlib.h>

Brick* brickListHead = NULL;

// void LoadLevel(int level, Brick bricks[BRICK_ROWS][BRICK_COLS]) {
//     for (int i = 0; i < BRICK_ROWS; i++) {
//         for (int j = 0; j < BRICK_COLS; j++) {
//             int tipebalok = levels[currentLevel].brickPattern[i][j];
//             if (tipebalok == 1) {
//                 bricks[i][j].isActive = true;
//                 bricks[i][j].color = BLUE;
//             } else {
//                 bricks[i][j].isActive = false;
//             }
//         }
//     }
// }

Brick* LoadLevel(int level) {
    Brick* head = NULL;
    Brick* tail = NULL;

    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            Brick* newBrick = (Brick*)malloc(sizeof(Brick));
            newBrick->row = i;
            newBrick->col = j;
            newBrick->isActive = true;
            newBrick->next = NULL;

            if (head == NULL) {
                head = newBrick;
                tail = newBrick;
            } else {
                tail->next = newBrick;
                tail = newBrick;
            }
        }
    }

    return head;
}

// void UpdateBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
//     for (int i = 0; i < BRICK_ROWS; i++) {
//         for (int j = 0; j < BRICK_COLS; j++) {
//             if (!bricks[i][j].isActive) {
//                 bricks[i][j].color.a = 0;
//             }
//         }
//     }
// }

void UpdateBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    Brick* current = brickListHead;
    while (current != NULL) {
        if (!current->isActive) {
            current->color.a = 0;
        }
        current = current->next; //
    }
}

// void DrawBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
//     for (int i = 0; i < BRICK_ROWS; i++) {
//         for (int j = 0; j < BRICK_COLS; j++) {
//             if (bricks[i][j].isActive) {
//                 Color brickColor = (bricks[i][j].isIndestructible) ? GRAY : BLUE;
//                 DrawRectangleRec(bricks[i][j].kotak, brickColor);
//                 bricks[0][0].isIndestructible = true;  
//             }
//         }
//     }
// }

void DrawBricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    Brick* current = brickListHead;
    while (current != NULL) {
        if (current->isActive) {
            Color brickColor = (current->isIndestructible) ? GRAY : current->color;
            DrawRectangleRec(current->kotak, brickColor);
        }
        current = current->next;
    }
}