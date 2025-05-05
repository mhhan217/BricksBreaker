#include "raylib.h"
#include "../Include/Hanif.h"
#include <math.h>

void initBall(Ball* ball, Vector2 ballSpeed, Paddle* paddle) {
    ball->Speed = ballSpeed;
    ball->Radius = 10;
    ball->Color = RAYWHITE;
    ball->Active = true;
    ball->Released = false;
    ball->Position.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
    ball->Position.y = paddle->Posisi.y - ball->Radius;
}

void updateBall(Ball* ball, Vector2 SpeedBola, Paddle* paddle) {
    if (!ball->Active) return;

    for (int i = LONG_EFFECT - 1; i > 0; i--) {
        ball->Effect[i] = ball->Effect[i - 1];
    }
    ball->Effect[0] = ball->Position;

    if (!ball->Released) {
        ball->Position.x = paddle->Posisi.x + paddle->Ukuran.x / 2;
        ball->Position.y = paddle->Posisi.y - ball->Radius;
        ball->Speed = SpeedBola;

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

void setSpeedBall(Ball* ball, Level* level) {
    switch (level->DifficultLevel) {
        case EASY:  ball->Speed = (Vector2){0, -10}; break;
        case MEDIUM: ball->Speed = (Vector2){0, -15}; break;
        case HARD: ball->Speed = (Vector2){0, -20}; break;
        default: ball->Speed = (Vector2){0, -10};
    }
}

Vector2 getSpeedBall(Ball* ball) {
    return ball->Speed;
}
