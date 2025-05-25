#include "raylib.h"
#include "../Include/Hanif.h"
#include "../Include/Zahwa.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void initBall(Ball* ball,Vector2 ballSpeed,Paddle* paddle){
    ball->Speed = ballSpeed;
    ball->Radius = 10;
    ball->Color = RAYWHITE;
    ball->Active = true;
    ball->Released = false;
    ball->Position.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
    ball->Position.y = paddle->Posisi.y - ball->Radius;
}

void updateBall(Ball* ball,Paddle* paddle,Vector2 ballSpeed) {
    if (!ball->Active) return;

    for (int i = LONG_EFFECT - 1; i > 0; i--) {
        ball->Effect[i] = ball->Effect[i - 1];
    }
    ball->Effect[0] = ball->Position;

    if (!ball->Released) {
        ball->Position.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
        ball->Position.y = paddle->Posisi.y - ball->Radius;
        ball->Speed = ballSpeed;

        if (IsKeyPressed(KEY_SPACE)) {
            ball->Released = true;
        }
    }

    if (ball->Released) {
        ball->Position.x += ball->Speed.x;
        ball->Position.y += ball->Speed.y;

        if (ball->Position.x - ball->Radius <= 0 || ball->Position.x + ball->Radius >= GetScreenWidth()) {
            ball->Speed.x *= -1;
        }

        if (ball->Position.y - ball->Radius <= 0) {
            ball->Speed.y *= -1;
        }

        if (ball->Position.y + ball->Radius >= paddle->Posisi.y &&
            ball->Position.x >= paddle->Posisi.x &&
            ball->Position.x <= paddle->Posisi.x + paddle->Ukuran.x) {

            float posisiPantulan = (ball->Position.x - (paddle->Posisi.x + paddle->Ukuran.x / 2)) / (paddle->Ukuran.x / 2);
            float sudutPantulan = posisiPantulan * 45 * (PI / 180.0f);

            float speedTotal = sqrtf(ball->Speed.x * ball->Speed.x + ball->Speed.y * ball->Speed.y);
            ball->Speed.x = sinf(sudutPantulan) * speedTotal;
            ball->Speed.y = -cosf(sudutPantulan) * speedTotal;

            if (fabs(ball->Speed.x) < 2.0f) {
                ball->Speed.x = (ball->Speed.x > 0) ? 2.0f : -2.0f;
            }
            if (fabs(ball->Speed.y) < 3.0f) {
                ball->Speed.y = (ball->Speed.y > 0) ? 3.0f : -3.0f;
            }
        }

        if (ball->Position.y + ball->Radius >= GetScreenHeight()) {
            ball->Released = false;
        }
    }
}

void drawBall(Ball* ball) {
    if (ball->Active) {
        for (int i = 0; i < LONG_EFFECT; i++) {
            float jejak_Effect = (float)(LONG_EFFECT - i) / LONG_EFFECT;
            Color EffectColor = Fade(ball->Color, jejak_Effect);
            DrawCircleV(ball->Effect[i], ball->Radius - i * 0.3, EffectColor);
        }
        DrawCircleV(ball->Position, ball->Radius, ball->Color);
    }
}

void setSpeedBall(Level* level,Ball* ball) {
    switch (level->DifficultLevel) {
        case EASY:  ball -> Speed = (Vector2){0, -15};break;
        case MEDIUM: ball -> Speed = (Vector2){0, -20};break;
        case HARD: ball -> Speed = (Vector2){0, -25};break;
        default: ball -> Speed = (Vector2){0, -20}; // Default ke EASY
    }
}

Vector2 getSpeedBall(Ball* ball) {
    return ball->Speed;
}



/*
// Menambahkan node ke awal linked list, dan menghapus yang berlebih jika panjang melebihi maxLength
void AddEffect(EffectNode** head, Vector2 posisi, int maxLength) {
    EffectNode* newNode = (EffectNode*)malloc(sizeof(EffectNode));
    newNode->posisi = posisi;
    newNode->next = *head;
    *head = newNode;

    // Potong jika panjang melebihi batas
    int count = 1;
    EffectNode* current = *head;
    while (current->next != NULL) {
        count++;
        if (count >= maxLength) {
            EffectNode* toDelete = current->next;
            current->next = NULL;
            while (toDelete != NULL) {
                EffectNode* temp = toDelete;
                toDelete = toDelete->next;
                free(temp);
            }
            break;

        }
        current = current->next;
    }
}


Membersihkan semua node dalam linked list
void FreeEffectList(EffectNode** head) {
    EffectNode* current = *head;
    while (current != NULL) {
        EffectNode* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
*/