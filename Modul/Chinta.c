#include <stdio.h>
#include "raylib.h"
#include "Chinta.h"
#include "Hanif.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

Vector2 ballPosition = { 400, 550 };
Vector2 ballSpeed = { 3, -3 };

float paddleSpeed = 5.0f;  // Atur kecepatan paddle sesuai kebutuhan
Vector2 paddlePosition = { 350, 550 }; // Atur posisi awal paddle

GameState gameState;
Level level;
// Ball ball;
int selectedMenuOption = 0;
// int menuIndex = 0;
// int currentDifficulty = 0;
int selectedDifficulty = 0;
int currentState = MENU;
int selectedLevel = 1;
int selectedPaddleColorIndex = 0;
int selectedBallColorIndex = 0;
float musicVolume = 1.0f;
float soundVolume = 1.0f;

Color paddleColors[6] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };
Color ballColors[6] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };
Color paddleColor = WHITE;
Color ballColor = WHITE;

Sound ballBounce;
Music gameMusic;

void displayMenuWithGraphics() {
    InitWindow(800, 600, "Bricks Breaker Menu");
    SetTargetFPS(60);
    // InitAudioDevice();
    inisialisasibacksound1();

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

        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
            panggilbacksound1();
            selectedMenuOption = (selectedMenuOption + 1) % menuCount;
        }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
            panggilbacksound1();
            selectedMenuOption = (selectedMenuOption - 1 + menuCount) % menuCount;
        }

        for (int i = 0; i < menuCount; i++) {
            Color textColor = (i == selectedMenuOption) ? highlightColors[i] : WHITE;
            DrawText(menuOptions[i], 350, 150 + (i * 60), 30, textColor);
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            if (selectedMenuOption == 0) break;
            else if (selectedMenuOption == 1) displayInfo();
            else if (selectedMenuOption == 2) displaySettings();
            else if (selectedMenuOption == 3) break;
        }

        EndDrawing();
    }
    tutupbacksound1();
    // CloseAudioDevice();
    CloseWindow();
}

// Fungsi untuk menggambar teks dengan bayangan
void DrawTextShadow(const char *text, int posX, int posY, int fontSize, Color textColor, Color shadowColor) {
    DrawText(text, posX + 2, posY + 2, fontSize, shadowColor); // Bayangan
    DrawText(text, posX, posY, fontSize, textColor);           // Teks utama
}

// // Fungsi untuk menampilkan menu pemilihan level
// void displayLevelSelection() {
//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(BLACK_BG);

//         DrawText("P", 280, 50, 30, MY_DARK_PINK);
//         DrawText("I", 300, 50, 30, MY_BLUE);
//         DrawText("L", 320, 50, 30, MY_GREEN);
//         DrawText("I", 340, 50, 30, MY_YELLOW);
//         DrawText("H", 360, 50, 30, MY_DARK_PINK);
//         DrawText(" ", 480, 50, 30, MY_BLUE);
//         DrawText("L", 400, 50, 30, MY_GREEN);
//         DrawText("E", 420, 50, 30, MY_YELLOW);
//         DrawText("V", 440, 50, 30, MY_DARK_PINK);
//         DrawText("E", 460, 50, 30, MY_BLUE);
//         DrawText("L", 480, 50, 30, MY_GREEN);

//         // Tampilkan pilihan kesulitan
//         const char *difficulties[] = {"EASY", "MEDIUM", "HARD"};
//         Color difficultyColor = (menuIndex == 0) ? MY_DARK_PINK : WHITE;
//         DrawText(difficulties[currentDifficulty], 350, 150, 30, difficultyColor);

//         // Tampilkan level yang dipilih
//         char levelText[20];
//         sprintf(levelText, "LEVEL %d", selectedLevel);
//         Color levelColor = (menuIndex == 1) ? MY_BLUE : WHITE;
//         DrawText(levelText, 340, 250, 30, levelColor);

//         // Tampilkan "START GAME"
//         Color startColor = (menuIndex == 2) ? MY_GREEN : WHITE;
//         DrawText("START GAME", 300, 350, 30, startColor);

//         // Tampilkan "BACK"
//         Color backColor = (menuIndex == 3) ? MY_YELLOW : WHITE;
//         DrawText("BACK", 350, 450, 30, backColor);

//         handleLevelSelectionInput();

//         EndDrawing();
//     }
// }

// Fungsi untuk menangani input dalam menu pemilihan level
// void handleLevelSelectionInput() {
//     if (IsKeyPressed(KEY_DOWN)) menuIndex = (menuIndex + 1) % 4;
//     if (IsKeyPressed(KEY_UP)) menuIndex = (menuIndex - 1 + 4) % 4;

//     if (menuIndex == 0) { // Navigasi kesulitan
//         if (IsKeyPressed(KEY_RIGHT)) currentDifficulty = (currentDifficulty + 1) % 3;
//         if (IsKeyPressed(KEY_LEFT)) currentDifficulty = (currentDifficulty - 1 + 3) % 3;
//     }
//     if (menuIndex == 1) { // Navigasi level
//         if (IsKeyPressed(KEY_RIGHT)) selectedLevel = (selectedLevel % 30) + 1;
//         if (IsKeyPressed(KEY_LEFT)) selectedLevel = (selectedLevel - 2 + 30) % 30 + 1;
//     }
//     if (menuIndex == 2 && IsKeyPressed(KEY_ENTER)) currentState = LOADING;
//     if (menuIndex == 3 && IsKeyPressed(KEY_ENTER)) currentState = MENU;

// }

void displayInfo() 
{
    int page = 1;
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        if (page == 1) 
        {
            DrawText("P", 320, 100, 30, MY_BLUE);
            DrawText("o", 340, 100, 30, MY_GREEN);
            DrawText("w", 360, 100, 30, MY_YELLOW);
            DrawText("e", 380, 100, 30, MY_DARK_PINK);
            DrawText("r", 400, 100, 30, MY_BLUE);
            DrawText("-", 420, 100, 30, MY_GREEN);
            DrawText("u", 440, 100, 30, MY_YELLOW);
            DrawText("p", 460, 100, 30, MY_DARK_PINK);
            DrawText("1. Enlarge Paddle - Memperbesar paddle", 200, 175, 20, WHITE_TEXT);
            DrawText("2. Shrink Paddle - Mengecilkan paddle", 200, 225, 20, WHITE_TEXT);
            DrawText("3. Speed Up Ball - Mempercepat bola", 200, 275, 20, WHITE_TEXT);
        } 
        else if (page == 2) 
        {
            DrawText("P", 320, 100, 30, MY_BLUE);
            DrawText("o", 340, 100, 30, MY_GREEN);
            DrawText("w", 360, 100, 30, MY_YELLOW);
            DrawText("e", 380, 100, 30, MY_DARK_PINK);
            DrawText("r", 400, 100, 30, MY_BLUE);
            DrawText("-", 420, 100, 30, MY_GREEN);
            DrawText("u", 440, 100, 30, MY_YELLOW);
            DrawText("p", 460, 100, 30, MY_DARK_PINK);
            DrawText("4. Slow Down Ball - Memperlambat bola", 200, 175, 20, WHITE_TEXT);
            DrawText("5. Extra Life - Menambah nyawa pemain", 200, 225, 20, WHITE_TEXT);
        }

        DrawText("Press B to go back", 300, 350, 20, MY_YELLOW);

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) 
        {
            if (page == 2) page = 1;
        }
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) 
        {
            if (page == 1) page = 2;
        }
        if (IsKeyPressed(KEY_B) || IsKeyPressed(KEY_ESCAPE)) 
        {
            break;
        }
        EndDrawing();
    }
}

void displaySettings() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        DrawText("S", 330, 50, 30, MY_BLUE);
        DrawText("e", 350, 50, 30, MY_GREEN);
        DrawText("t", 370, 50, 30, MY_YELLOW);
        DrawText("t", 390, 50, 30, MY_DARK_PINK);
        DrawText("i", 410, 50, 30, MY_BLUE);
        DrawText("n", 420, 50, 30, MY_GREEN);
        DrawText("g", 440, 50, 30, MY_YELLOW);
        DrawText("s", 460, 50, 30, MY_DARK_PINK);

        DrawText("Paddle Color:", 200, 120, 20, WHITE);
        DrawRectangle(400, 120, 40, 40, paddleColors[selectedPaddleColorIndex]);
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) ChangePaddleColor(-1);
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) ChangePaddleColor(1);

        DrawText("Ball Color:", 200, 180, 20, WHITE);
        DrawRectangle(400, 180, 40, 40, ballColors[selectedBallColorIndex]);
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) ChangeBallColor(-1);
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) ChangeBallColor(1);

        DrawText("Music Volume:", 200, 240, 20, WHITE);
        DrawText("< W / S >", 400, 240, 20, YELLOW);
        if (IsKeyPressed(KEY_W)) IncreaseVolume();
        if (IsKeyPressed(KEY_S)) DecreaseVolume();

        DrawText("Sound Effects:", 200, 300, 20, WHITE);
        DrawText("< A / D >", 400, 300, 20, YELLOW);
        if (IsKeyPressed(KEY_A)) DecreaseSound();
        if (IsKeyPressed(KEY_D)) IncreaseSound();

        DrawText("Press B to go back", 300, 400, 20, MY_GREEN);
        if (IsKeyPressed(KEY_B)) return;

        EndDrawing();
    }
}

void ChangePaddleColor(int direction) 
{
    selectedPaddleColorIndex = (selectedPaddleColorIndex + direction + 6) % 6;
    paddleColor = paddleColors[selectedPaddleColorIndex];
}

void ChangeBallColor(int direction) 
{
    selectedBallColorIndex = (selectedBallColorIndex + direction + 6) % 6;
    ballColor = ballColors[selectedBallColorIndex];
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

void playGame() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) paddlePosition.x -= paddleSpeed;
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) paddlePosition.x += paddleSpeed;

        if (paddlePosition.x < 0) paddlePosition.x = 0;
        if (paddlePosition.x > 800 - 100) paddlePosition.x = 800 - 100;

        DrawRectangle(paddlePosition.x, paddlePosition.y, 100, 20, paddleColor);
        DrawText("Press B to go back", 300, 400, 20, MY_YELLOW);
        if (IsKeyPressed(KEY_B)) return;

        EndDrawing();
    }
}
