#ifndef CHINTA_H
#define CHINTA_H

#include <stdio.h>
#include "raylib.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

#define MY_DARK_PINK (Color){ 199, 21, 133, 255 }
#define MY_BLUE (Color){ 0, 0, 255, 255 }
#define MY_GREEN (Color){ 0, 255, 0, 255 }
#define MY_YELLOW (Color){ 255, 255, 0, 255 }
#define BLACK_BG (Color){ 0, 0, 0, 255 }
#define WHITE_TEXT (Color){ 255, 255, 255, 255 }

extern Vector2 ballPosition;
extern Vector2 ballSpeed;
extern int selectedDifficulty;
extern int selectedPaddleColorIndex;
extern int selectedBallColorIndex;
extern Color paddleColor;
extern Color ballColor;
extern bool isMuted;
extern bool isDraggingMusic;
extern bool isDraggingSound;
extern float musicVolume;
extern float soundVolume;
extern Sound ballBounce;
extern Music gameMusic;

extern Color paddleColors[6];
extern Color ballColors[6];

bool DrawButton(Rectangle rect, const char *text, Color outlineColor, Color textColor);
void displayMenuWithGraphics();
void displayDifficultyMenu();
void displayInfo();
void displaySettings();
void ChangePaddleColor(int direction);
void ChangeBallColor(int direction);
void IncreaseVolume();
void DecreaseVolume();
void playGame();

#endif // CHINTA_H
