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

void startGame(ScreenControl *screen);

#endif // HANIF_H
