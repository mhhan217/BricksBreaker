#include <stdio.h>
#include "raylib.h"
#include "../Include/Zidan.h"
#include <time.h>
#include <stdlib.h>

LevelZidan* levelListHead = NULL;
BrickZidan* brickListHead = NULL;

Color WarnaAcak() {
    return (rand() % 2 == 0) ? BLUE : GRAY;
}

PatternNodeZidan* CreatePattern() {
    PatternNodeZidan* head = NULL;
    PatternNodeZidan* tail = NULL;

    for (int i = 0; i < 10; i++) { // 10 rows
        for (int j = 0; j < 5; j++) { // 5 cols
            if (i % 2 == 0) {
                PatternNodeZidan* node = (PatternNodeZidan*)malloc(sizeof(PatternNodeZidan));
                node->row = i;
                node->col = j;
                node->value = (j % 2 == 0) ? 1 : 2;
                node->next = NULL;

                if (head == NULL) {
                    head = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            }
        }
    }

    return head;
}

void AddLevel(int number, PatternNodeZidan* patternList) {
    LevelZidan* newLevel = (LevelZidan*)malloc(sizeof(LevelZidan));
    newLevel->NumberLevel = number;
    newLevel->patternList = patternList;
    newLevel->next = NULL;

    if (levelListHead == NULL) {
        levelListHead = newLevel;
    } else {
        LevelZidan* current = levelListHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newLevel;
    }
}

LevelZidan* GetLevelByNumber(int number) {
    LevelZidan* current = levelListHead;
    while (current != NULL) {
        if (current->NumberLevel == number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

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

BrickZidan* LoadLevelFromPatternList(PatternNodeZidan* patternList) {
    BrickZidan* head = NULL;
    BrickZidan* tail = NULL;

    PatternNodeZidan* currentPattern = patternList;
    while (currentPattern != NULL) {
        BrickZidan* newBrick = (BrickZidan*)malloc(sizeof(BrickZidan));
        newBrick->row = currentPattern->row;
        newBrick->col = currentPattern->col;
        newBrick->isActive = true;
        newBrick->isIndestructible = (currentPattern->value == 2);
        newBrick->color = (currentPattern->value == 2) ? RED : BLUE;
        newBrick->kotak = (Rectangle){0}; // akan diatur kemudian
        newBrick->next = NULL;

        if (head == NULL) {
            head = newBrick;
            tail = newBrick;
        } else {
            tail->next = newBrick;
            tail = newBrick;
        }

        currentPattern = currentPattern->next;
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

void UpdateBricks(BrickZidan* brickList) {
    BrickZidan* current = brickList;
    while (current != NULL) {
        if (!current->isActive) {
            current->color.a = 0;
        }
        current = current->next;
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

void DrawBricks(BrickZidan* brickList) {
    BrickZidan* current = brickList;
    while (current != NULL) {
        if (current->isActive) {
            Color brickColor = current->isIndestructible ? GRAY : current->color;
            DrawRectangleRec(current->kotak, brickColor);
        }
        current = current->next;
    }
}

// void SetupGameLevels() {
//     PatternNodeZidan* pattern1 = CreatePattern();
//     AddLevel(1, pattern1);

//     LevelZidan* level = GetLevelByNumber(1);
//     brickListHead = LoadLevelFromPatternList(level->patternList);
//     InitializeBricks(brickListHead);
// }