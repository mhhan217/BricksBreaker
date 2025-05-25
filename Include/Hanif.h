#ifndef HANIF_H
#define HANIF_H
#include <stdbool.h>
#include "raylib.h"
#include "Konfigurasi.h"
#include "Zahwa.h"
#define LONG_EFFECT 15
#define BRICK_ROWS 30
#define BRICK_COLS 30


typedef struct EffectNode {
    Vector2 posisi;
    struct EffectNode* next;
} EffectNode;

typedef struct Ball{
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
    int brickPattern[BRICK_ROWS][BRICK_COLS];
}Level;

//Ball
void initBall(Ball* ball,Vector2 ballSpeed,Paddle* paddle);
void updateBall(Ball* ball,Paddle* paddle,Vector2 ballSpeed);
void drawBall(Ball *ball);
void setSpeedBall(Level* level,Ball* ball);
Vector2 getSpeedBall(Ball* ball);
//Handlelevel
void handleLevelSelectionInput(GameState* gameState,Level* level,Ball* ball);
void difficultLevel(Level *level);
int numberLevel(Level *level);
void drawLevel(Level *level);

//Handle game
void updateGame(GameState *gameState);
void drawGame(GameState *gametState);

//handle pause
void DrawPauseScreen(GameState* gamestate);
void HandlePauseInput(GameState* gamestate);

static inline void AddEffect(EffectNode** head, Vector2 posisi, int maxLength);
static inline void FreeEffectList(EffectNode** head);


EffectNode effectnode;


















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

#endif//HANIF_H