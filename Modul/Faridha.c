#include "Faridha.h"

void TampilkanMenu(int score, bool *playAgain, bool *exitGame) {
    int selected = 0;
    const char *menuOptions[] = { "Play Again", "Exit" };
    int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) selected = (selected + 1) % menuSize;
        if (IsKeyPressed(KEY_UP)) selected = (selected - 1 + menuSize) % menuSize;

        if (IsKeyPressed(KEY_ENTER)) {
            if (selected == 0) *playAgain = true;
            if (selected == 1) *exitGame = true;
            return;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Brick Breaker", SCREEN_WIDTH / 2 - 100, 100, 30, DARKGRAY);
        DrawText(TextFormat("Score: %d", score), SCREEN_WIDTH / 2 - 50, 200, 20, BLACK);

        for (int i = 0; i < menuSize; i++) {
            Color color = (i == selected) ? RED : BLACK;
            DrawText(menuOptions[i], SCREEN_WIDTH / 2 - 50, 300 + i * 50, 20, color);
        }

        EndDrawing();
    }
}

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker Menu");
    SetTargetFPS(60);

    int score = 0;
    bool playAgain = false;
    bool exitGame = false;

    while (!exitGame) {
        TampilkanMenu(score, &playAgain, &exitGame);

        if (playAgain) {
            playAgain = false;
            score += 10; // Simulasi peningkatan skor
        }
    }

    CloseWindow();
    return 0;
}
