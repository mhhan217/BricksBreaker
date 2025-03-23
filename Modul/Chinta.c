#include <stdio.h>
#include "raylib.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Chinta.h"
#include "../Include/Hanif.h"
#define MY_DARK_PINK (Color){ 199, 21, 133, 255 }
#define MY_BLUE (Color){ 0, 0, 255, 255 }
#define MY_GREEN (Color){ 0, 255, 0, 255 }
#define MY_YELLOW (Color){ 255, 255, 0, 255 }
#define BLACK_BG (Color){ 0, 0, 0, 255 }
#define WHITE_TEXT (Color){ 255, 255, 255, 255 }

float musicVolume = 1.0f;
float soundVolume = 1.0f;

Sound ballBounce;
Music gameMusic;

Level level;
Ball ball;

void displayMenu(ScreenControl *screen) {
    InitWindow(800, 600, "Bricks Breaker Menu");
    SetTargetFPS(60);
    InitAudioDevice();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        DrawText("B", 250, 50, 30, MY_DARK_PINK);
        DrawText("r", 270, 50, 30, MY_BLUE);
        DrawText("i", 290, 50, 30, MY_GREEN);
        DrawText("c", 310, 50, 30, MY_YELLOW);
        DrawText("k", 330, 50, 30, MY_DARK_PINK);
        DrawText("s", 350, 50, 30, MY_BLUE);
        DrawText(" ", 370, 50, 30, MY_GREEN);
        DrawText("B", 390, 50, 30, MY_YELLOW);
        DrawText("r", 410, 50, 30, MY_DARK_PINK);
        DrawText("e", 430, 50, 30, MY_BLUE);
        DrawText("a", 450, 50, 30, MY_GREEN);
        DrawText("k", 470, 50, 30, MY_YELLOW);
        DrawText("e", 490, 50, 30, MY_DARK_PINK);
        DrawText("r", 510, 50, 30, MY_BLUE);
        DrawText(" ", 530, 50, 30, MY_GREEN);
        DrawText("G", 550, 50, 30, MY_YELLOW);
        DrawText("a", 570, 50, 30, MY_DARK_PINK);
        DrawText("m", 590, 50, 30, MY_BLUE);
        DrawText("e", 610, 50, 30, MY_GREEN);

        const char *menuOptions[] = { "Play", "Info", "Settings", "Exit" };
        Color highlightColors[] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW };
        int menuCount = 4;

        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
            screen->index = (screen->index + 1) % menuCount;
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
            screen->index = (screen->index - 1 + menuCount) % menuCount;

        for (int i = 0; i < menuCount; i++) {
            Color textColor = (i == screen->index) ? highlightColors[i] : WHITE;
            DrawText(menuOptions[i], 350, 150 + (i * 60), 30, textColor);
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            if (screen->index == 0) displayLevel(screen);
            else if (screen->index == 1) displayInfo(screen);
            else if (screen->index == 2) displaySettings(screen);
            else if (screen->index == 3) break;
        }

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
}

void displayLevel(ScreenControl *screen) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        // Judul dengan warna berbeda
        DrawText("P", 280, 50, 30, MY_DARK_PINK);
        DrawText("I", 300, 50, 30, MY_BLUE);
        DrawText("L", 320, 50, 30, MY_GREEN);
        DrawText("I", 340, 50, 30, MY_YELLOW);
        DrawText("H", 360, 50, 30, MY_DARK_PINK);
        DrawText(" ", 480, 50, 30, MY_BLUE);
        DrawText("L", 400, 50, 30, MY_GREEN);
        DrawText("E", 420, 50, 30, MY_YELLOW);
        DrawText("V", 440, 50, 30, MY_DARK_PINK);
        DrawText("E", 460, 50, 30, MY_BLUE);
        DrawText("L", 480, 50, 30, MY_GREEN);

        // Opsi kesulitan
        const char *difficulties[] = {"EASY", "MEDIUM", "HARD"};
        Color difficultyColor = (screen->index == 0) ? MY_DARK_PINK : WHITE;
        DrawText(difficulties[level.DifficultLevel], 350, 150, 30, difficultyColor);

        // Opsi pemilihan level
        char levelText[20];
        sprintf(levelText, "LEVEL %d", level.NumberLevel);
        Color levelColor = (screen->index == 1) ? MY_BLUE : WHITE;
        DrawText(levelText, 340, 250, 30, levelColor);

        // Opsi start game
        Color startColor = (screen->index == 2) ? MY_GREEN : WHITE;
        DrawText("START GAME", 300, 350, 30, startColor);

        // Opsi kembali
        Color backColor = (screen->index == 3) ? MY_YELLOW : WHITE;
        DrawText("BACK", 350, 450, 30, backColor);
        handleLevelSelectionInput(screen,&level,&ball);

        EndDrawing();
    }
}


void displayInfo(ScreenControl *screen) 
{
    int page = 1;

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        // Judul "Power-up"
        DrawText("P", 320, 100, 30, MY_BLUE);
        DrawText("o", 340, 100, 30, MY_GREEN);
        DrawText("w", 360, 100, 30, MY_YELLOW);
        DrawText("e", 380, 100, 30, MY_DARK_PINK);
        DrawText("r", 400, 100, 30, MY_BLUE);
        DrawText("-", 420, 100, 30, MY_GREEN);
        DrawText("u", 440, 100, 30, MY_YELLOW);
        DrawText("p", 460, 100, 30, MY_DARK_PINK);

        // Isi halaman
        if (page == 1) 
        {
            DrawText("1. Enlarge Paddle - Memperbesar paddle", 200, 175, 20, WHITE_TEXT);
            DrawText("2. Shrink Paddle - Mengecilkan paddle", 200, 225, 20, WHITE_TEXT);
            DrawText("3. Speed Up Ball - Mempercepat bola", 200, 275, 20, WHITE_TEXT);
        } 
        else if (page == 2) 
        {
            DrawText("4. Slow Down Ball - Memperlambat bola", 200, 175, 20, WHITE_TEXT);
            DrawText("5. Extra Life - Menambah nyawa pemain", 200, 225, 20, WHITE_TEXT);
        }

        DrawText("Press B to go back", 300, 350, 20, MY_YELLOW);

        // Navigasi antar halaman
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) 
        {
            if (page == 2) page = 1;
        }
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) 
        {
            if (page == 1) page = 2;
        }

        // Back to menu
        if (IsKeyPressed(KEY_B) || IsKeyPressed(KEY_ESCAPE)) break;

        EndDrawing();
    }
}

void displaySettings(ScreenControl *screen) 
{
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        // Judul "Settings"
        DrawText("S", 330, 50, 30, MY_BLUE);
        DrawText("e", 350, 50, 30, MY_GREEN);
        DrawText("t", 370, 50, 30, MY_YELLOW);
        DrawText("t", 390, 50, 30, MY_DARK_PINK);
        DrawText("i", 410, 50, 30, MY_BLUE);
        DrawText("n", 420, 50, 30, MY_GREEN);
        DrawText("g", 440, 50, 30, MY_YELLOW);
        DrawText("s", 460, 50, 30, MY_DARK_PINK);

        // Ubah warna paddle
        // DrawText("Paddle Color:", 200, 120, 20, WHITE);
        // DrawRectangle(400, 120, 40, 40, paddleColors[selectedPaddleColorIndex]);

        // Ubah warna bola
        // DrawText("Ball Color:", 200, 180, 20, WHITE);
        // DrawRectangle(400, 180, 40, 40, ballColors[selectedBallColorIndex]);

        // Music Volume
        DrawText("Music Volume:", 200, 240, 20, WHITE);
        DrawRectangle(400, 245, 200, 10, GRAY); 
        DrawRectangle(400, 245, (int)(musicVolume * 200), 10, MY_GREEN); 
        DrawText(TextFormat("%d", (int)(musicVolume * 100)), 610, 240, 20, YELLOW);
        
        // Sound Effects
        DrawText("Sound Effects:", 200, 300, 20, WHITE);
        DrawRectangle(400, 305, 200, 10, GRAY);
        DrawRectangle(400, 305, (int)(soundVolume * 200), 10, MY_YELLOW);
        DrawText(TextFormat("%d", (int)(soundVolume * 100)), 610, 300, 20, YELLOW);

        // Back to Menu
        DrawText("Press B to go back", 300, 400, 20, MY_GREEN);

        // Handle Input
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) IncreaseVolume();
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) DecreaseVolume();
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) IncreaseSound();
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) DecreaseSound();

        if (IsKeyPressed(KEY_B)) return;

        EndDrawing();
    }
}

void IncreaseVolume() 
{
    if (musicVolume < 1.0f) musicVolume += 0.1f;
    SetMusicVolume(gameMusic, musicVolume);
}

void DecreaseVolume() 
{
    if (musicVolume > 0.0f) musicVolume -= 0.1f;
    SetMusicVolume(gameMusic, musicVolume);
}

void IncreaseSound() 
{
    if (soundVolume < 1.0f) soundVolume += 0.1f;
    SetSoundVolume(ballBounce, soundVolume);
}

void DecreaseSound() 
{
    if (soundVolume > 0.0f) soundVolume -= 0.1f;
    SetSoundVolume(ballBounce, soundVolume);
}

void displayPause(ScreenControl *screen) {
    const char *menuItems[] = {"Resume", "Settings", "Restart", "Menu"};
    const Color menuColors[] = {MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW}; // Warna buat menu
    const int menuCount = 4;

    while (!WindowShouldClose()) {
        // Handle input
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            screen->index = (screen->index == 0) ? menuCount - 1 : screen->index - 1;
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            screen->index = (screen->index == menuCount - 1) ? 0 : screen->index + 1;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (screen->index) {
                case 0: return; // Resume
                case 1: screen->gameState = SETTINGS; return;
                case 2: screen->gameState = LEVEL_SELECTION; return;
                case 3: screen->gameState = MENU; return;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Judul "PAUSED"
        DrawText("P", 320, 50, 40, MY_BLUE);
        DrawText("A", 345, 50, 40, MY_GREEN);
        DrawText("U", 370, 50, 40, MY_YELLOW);
        DrawText("S", 395, 50, 40, MY_DARK_PINK);
        DrawText("E", 420, 50, 40, MY_BLUE);
        DrawText("D", 445, 50, 40, MY_GREEN);

        // Menu pause
        for (int i = 0; i < menuCount; i++) {
            int x = SCREEN_WIDTH / 2 - MeasureText(menuItems[i], 30) / 2;
            int y = 150 + (i * 60);
            Color color = (i == screen->index) ? menuColors[i] : WHITE;
            DrawText(menuItems[i], x, y, 30, color);
        }

        EndDrawing();
    }
}
