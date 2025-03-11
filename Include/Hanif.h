#ifndef HANIF_H
#define HANIF_H
#include "raylib.h"
#include "Konfigurasi.h"

#define LONG_EFFECT 15

typedef struct{
    Vector2 Position;
    Vector2 Speed;
    float Radius;
    Vector2 Effect[LONG_EFFECT];
    Color Color;
    bool Active;
    bool Released;
}Ball;

typedef enum {
    EASY, MEDIUM, HARD
} Difficulty;

typedef struct {
    int NumberLevel;
    Difficulty DifficultLevel;
}Level;

void initBall(Ball* ball,Vector2 ballSpeed,Paddle* paddle);
void updateBall(Ball* ball,Paddle* paddle,Vector2 ballSpeed);
void drawBall(Ball ball);
void setSpeedBall(Ball* ball,Level* level);
Vector2 getSpeedBall(Ball* ball);
//Handlelevel
void handleLevelSelectionInput(ScreenControl* screen, Level *level,Ball* ball);
void difficultLevel(Level *level);
void numberLevel(Level *level);
void configlevel(Level *level);

//Handle game
void updateGame(GameState *gameState);
void drawGame(GameState *gametState);




















/*
typedef struct {
    Vector2 Posisi;
    Vector2 Ukuran;
    float Kecepatan;
    Color Warna;
} Paddle;

void InitPaddle(Paddle* paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan);
void UpdatePaddle(Paddle* paddle);
void DrawPaddle(Paddle paddle);

*/

#endif //HANIF_H
