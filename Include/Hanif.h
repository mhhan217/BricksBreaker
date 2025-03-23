#ifndef HANIF_H
#define HANIF_H

#include "raylib.h"
#include "Konfigurasi.h"
void initBall(Ball* ball, Vector2 ballSpeed, Paddle* paddle);
void updateBall(Ball* ball, Vector2 ballSpeed, Paddle* paddle);
void drawBall(Ball* ball);
void setSpeedBall(Ball* ball, Level* level);
Vector2 getSpeedBall(Ball* ball);

// Handle Level
void handleLevelSelectionInput(ScreenControl* screen, Level *level, Ball* ball);
void difficultLevel(Level *level);
void numberLevel(Level *level);
void configLevel(Level *level);

// Handle Game
void updateGame(ScreenControl* screen, Difficulty* selectDifficult, int *selectNumber);
void drawGame(ScreenControl* screen, Difficulty* selectDifficult, int *selectNumber);

#include "Zahwa.h" // Dipanggil setelah Ball didefinisikan

#endif // HANIF_H
