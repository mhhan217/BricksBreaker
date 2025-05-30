#ifndef CHINTA_H
#define CHINTA_H

#include <stdio.h>
#include "raylib.h"

// Ukuran tombol
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

// Warna kustom
#define MY_DARK_PINK (Color){ 199, 21, 133, 255 }
#define MY_BLUE (Color){ 0, 0, 255, 255 }
#define MY_GREEN (Color){ 0, 255, 0, 255 }
#define MY_YELLOW (Color){ 255, 255, 0, 255 }
#define BLACK_BG (Color){ 0, 0, 0, 255 }
#define WHITE_TEXT (Color){ 255, 255, 255, 255 }

// Deklarasi variabel global (gunakan `extern`)
extern Vector2 ballPosition;
extern Vector2 ballSpeed;
extern Vector2 paddlePosition;  // Ditambahkan
extern float paddleSpeed;       // Ditambahkan
extern int menuIndex;
extern int currentDifficulty;
extern int currentState;
extern int selectedDifficulty;
extern int selectedPaddleColorIndex;
extern int selectedBallColorIndex;
extern float musicVolume;
extern float soundVolume;
extern Sound ballBounce;
extern Music gameMusic;

typedef struct MenuTextNode {
    char text[50];
    struct MenuTextNode *next;
} MenuTextNode;

typedef struct ColorNode {
    Color color;
    struct ColorNode *next;
} ColorNode;

// Deklarasi array warna sebagai `extern`
extern Color paddleColor;
extern Color ballColor;
extern Color paddleColors[6];
extern Color ballColors[6];

// Deklarasi fungsi
void displayMenuWithGraphics();
void DrawTextShadow(const char *text, int posX, int posY, int fontSize, Color textColor, Color shadowColor);
void displayLevel();
void handleLevelSelectionInput();
void displayInfo();
void displaySettings();
void ChangePaddleColor(int direction);
void ChangeBallColor(int direction);
void IncreaseVolume();
void DecreaseVolume();
void IncreaseSound();
void DecreaseSound();
void playGame();

void appendMenuText(MenuTextNode **head, const char *text);
MenuTextNode* getMenuTextNodeAt(MenuTextNode *head, int index);
void appendColor(ColorNode **head, Color color);

#endif // CHINTA_H
