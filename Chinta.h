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

typedef struct {
    int index;
    int gameState;
} ScreenControl;

// Deklarasi variabel global (gunakan `extern`)
extern Vector2 ballPosition;
extern Vector2 ballSpeed;
extern Vector2 paddlePosition;  
extern float paddleSpeed;       
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

// Deklarasi array warna sebagai `extern`
extern Color paddleColor;
extern Color ballColor;
extern Color paddleColors[6];
extern Color ballColors[6];

// Deklarasi fungsi
void displayMenuWithGraphics(ScreenControl *screen);
void displayLevelSelection(ScreenControl *screen);
void DrawInfoScreen(int page);
// void handleLevelSelectionInput(ScreenControl *screen);
void HandleInfoInput(int *page);
void displayInfo(ScreenControl *screen);
void DrawSettingsScreen(ScreenControl *screen);
void HandleSettingsInput(ScreenControl *screen);
void displaySettings(ScreenControl *screen);
// void ChangePaddleColor(int direction);
// void ChangeBallColor(int direction);
void IncreaseVolume();
void DecreaseVolume();
void IncreaseSound();
void DecreaseSound();
void playGame(ScreenControl *screen);
void DrawPauseScreen(ScreenControl *screen);
void HandlePauseInput(ScreenControl *screen);

#endif // CHINTA_H
