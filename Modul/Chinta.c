#include <stdio.h>
#include "raylib.h"
#include "Chinta.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

Vector2 ballPosition = { 400, 550 };
Vector2 ballSpeed = { 3, -3 };

int selectedDifficulty = 0;

// Fungsi untuk menggambar tombol dengan efek saat ditekan
bool DrawButton(Rectangle rect, const char *text, Color outlineColor, Color textColor) 
{
    Vector2 mousePoint = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mousePoint, rect);
    bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    
    DrawRectangleRec(rect, clicked ? BLACK_BG : BLACK_BG);
    DrawRectangleLinesEx(rect, 3, outlineColor);
    int textWidth = MeasureText(text, 20);
    DrawText(text, rect.x + (BUTTON_WIDTH - textWidth) / 2, rect.y + 10, 20, clicked ? WHITE_TEXT : textColor);
    
    return clicked;
}

void displayMenuWithGraphics() 
{
    InitWindow(800, 600, "Bricks Breaker Menu");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        
        // Gambar bola
        DrawCircleV(ballPosition, 10, WHITE);

        // Pergerakan bola
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Pantulan dari dinding
        if (ballPosition.x <= 0 || ballPosition.x >= 800) ballSpeed.x *= -1;
        if (ballPosition.y <= 0 || ballPosition.y >= 600) ballSpeed.y *= -1;
        
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
        
        Rectangle playBtn = { 300, 150, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle infoBtn = { 300, 210, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle settingsBtn = { 300, 270, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle exitBtn = { 300, 330, BUTTON_WIDTH, BUTTON_HEIGHT };
        
        if (DrawButton(playBtn, "Play", MY_DARK_PINK, MY_DARK_PINK))
        {
            displayDifficultyMenu();
        }
        else if (DrawButton(infoBtn, "Info", MY_BLUE, MY_BLUE))
        {
            displayInfo();
        }
        else if (DrawButton(settingsBtn, "Settings", MY_GREEN, MY_GREEN))
        {
            displaySettings();
        }
        else if (DrawButton(exitBtn, "Exit", MY_YELLOW, MY_YELLOW))
        {
            break;
        }
        
        EndDrawing();
    }
    CloseWindow();
}

void displayDifficultyMenu()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        
        DrawText("d", 260, 50, 30, MY_BLUE);
        DrawText("i", 280, 50, 30, MY_GREEN);
        DrawText("f", 300, 50, 30, MY_YELLOW);
        DrawText("f", 320, 50, 30, MY_DARK_PINK);
        DrawText("i", 340, 50, 30, MY_BLUE);
        DrawText("c", 360, 50, 30, MY_GREEN);
        DrawText("u", 380, 50, 30, MY_YELLOW);
        DrawText("l", 400, 50, 30, MY_DARK_PINK);
        DrawText("t", 420, 50, 30, MY_BLUE);
        DrawText("y", 440, 50, 30, MY_GREEN);
        DrawText(" ", 460, 50, 30, MY_YELLOW);
        DrawText("l", 480, 50, 30, MY_YELLOW);
        DrawText("e", 500, 50, 30, MY_DARK_PINK);
        DrawText("v", 520, 50, 30, MY_BLUE);
        DrawText("e", 540, 50, 30, MY_GREEN);
        DrawText("l", 560, 50, 30, MY_YELLOW);
 
        
        Rectangle easyBtn = { 300, 150, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle mediumBtn = { 300, 210, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle hardBtn = { 300, 270, BUTTON_WIDTH, BUTTON_HEIGHT };
        Rectangle backBtn = { 300, 330, BUTTON_WIDTH, BUTTON_HEIGHT };
        
        if (DrawButton(easyBtn, "Easy", MY_DARK_PINK, MY_DARK_PINK))
        {
            selectedDifficulty = 1;
            playGame();
        }
        else if (DrawButton(mediumBtn, "Medium", MY_BLUE, MY_BLUE))
        {
            selectedDifficulty = 2;
            playGame();
        }
        else if (DrawButton(hardBtn, "Hard", MY_GREEN, MY_GREEN))
        {
            selectedDifficulty = 3;
            playGame();
        }
        else if (DrawButton(backBtn, "Back", MY_YELLOW, MY_YELLOW))
        {
            return;
        }
        
        EndDrawing();
    }
}

void displayInfo() 
{
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        DrawText("Power-ups:", 300, 100, 20, WHITE_TEXT);
        DrawText("1. Ball splits into 3", 300, 150, 20, WHITE_TEXT);
        DrawText("2. Paddle becomes longer", 300, 200, 20, WHITE_TEXT);
        
        Rectangle backBtn = { 300, 300, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(backBtn, "Back", MY_BLUE, MY_BLUE))
        {
            break;
        }
        EndDrawing();
    }
}

void displaySettings() 
{
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        DrawText("Music", 300, 100, 20, MY_DARK_PINK);
        
        Rectangle backBtn = { 300, 300, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(backBtn, "Back", MY_BLUE, MY_BLUE))
        {
            break;
        }
        EndDrawing();
    }
}

void playGame()
{
    Color textColor;
    const char *message;

    if (selectedDifficulty == 1) {
        textColor = MY_DARK_PINK;
        message = "Playing games at easy level..";
    } else if (selectedDifficulty == 2) {
        textColor = MY_BLUE;
        message = "Playing games at medium level..";
    } else if (selectedDifficulty == 3) {
        textColor = MY_GREEN;
        message = "Playing games at hard level..";
    } else {
        return;  // Jika tidak ada level yang dipilih, kembali
    }

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        
        DrawText(message, 250, 100, 20, textColor);

        Rectangle backBtn = { 300, 300, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(backBtn, "Back", MY_YELLOW, MY_YELLOW))
        {
            return;  // Kembali ke menu pemilihan tingkat kesulitan
        }

        EndDrawing();
    }
}
