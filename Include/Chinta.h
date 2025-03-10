#ifndef CHINTA_H
#define CHINTA_H
#include <stdio.h>
#include "raylib.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

bool DrawButton(Rectangle rect, const char *text, Color outlineColor, Color textColor);
void displayMenuWithGraphics();
void displayDifficultyMenu();
void displayInfo();
void displaySettings();
void playGame();
int selectedDifficulty = 0;

#endif //CHINTA_H
