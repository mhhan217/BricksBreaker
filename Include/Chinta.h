
#ifndef CHINTA_H
#define CHINTA_H
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40
#define MY_DARK_PINK (Color){ 199, 21, 133, 255 }
#define MY_BLUE (Color){ 0, 0, 255, 255 }
#define MY_GREEN (Color){ 0, 255, 0, 255 }
#define MY_YELLOW (Color){ 255, 255, 0, 255 }
#define BLACK_BG (Color){ 0, 0, 0, 255 }
#define WHITE_TEXT (Color){ 255, 255, 255, 255 }

#include <stdio.h>
#include "raylib.h"

extern int selectedDifficulty;

bool DrawButton(Rectangle rect, const char *text, Color outlineColor, Color textColor);
void displayMenuWithGraphics();
void displayDifficultyMenu();
void displayInfo();
void displaySettings();
void playGame();

#endif //CHINTA_H
