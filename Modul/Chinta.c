#include <stdio.h>
#include "raylib.h"
#include "Chinta.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

Vector2 ballPosition = { 400, 550 };
Vector2 ballSpeed = { 3, -3 };

int selectedDifficulty = 0;

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
        
        DrawCircleV(ballPosition, 10, WHITE);

        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        if (ballPosition.x <= 0 || ballPosition.x >= 800) ballSpeed.x *= -1;
        if (ballPosition.y <= 0 || ballPosition.#include <stdio.h>
#include "raylib.h"
#include "Chinta.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40

Vector2 ballPosition = { 400, 550 };
Vector2 ballSpeed = { 3, -3 };

int selectedDifficulty = 0;
int selectedPaddleColorIndex = 0;
int selectedBallColorIndex = 0;
Color paddleColor = WHITE;
Color ballColor = WHITE;
bool isMuted = false;
bool isDraggingMusic = false;
bool isDraggingSound = false;
float musicVolume = 1.0f;
float soundVolume = 1.0f;
Sound ballBounce;
Music gameMusic;

Color paddleColors[6] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };
Color ballColors[6] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };

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
    InitAudioDevice();

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
    CloseAudioDevice();
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

        Rectangle backBtn = { 50, 350, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (page == 2 && DrawButton(backBtn, "Back", MY_YELLOW, MY_YELLOW))
        {
            page = 1;
        }

        Rectangle mainMenuBtn = { 300, 350, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(mainMenuBtn, "Back to Main Menu", MY_BLUE, MY_BLUE))
        {
            break;
        }

        Rectangle nextBtn = { 550, 350, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (page == 1 && DrawButton(nextBtn, "Next", MY_GREEN, MY_GREEN))
        {
            page = 2;
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
        
        DrawText("S", 330, 50, 30, MY_BLUE);
        DrawText("e", 350, 50, 30, MY_GREEN);
        DrawText("t", 370, 50, 30, MY_YELLOW);
        DrawText("t", 390, 50, 30, MY_DARK_PINK);
        DrawText("i", 410, 50, 30, MY_BLUE);
        DrawText("n", 420, 50, 30, MY_GREEN);
        DrawText("g", 440, 50, 30, MY_YELLOW);
        DrawText("s", 460, 50, 30, MY_DARK_PINK);
        
        DrawText("Paddle Color:", 200, 120, 20, WHITE_TEXT);
        Color paddleColors[] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };
        for (int i = 0; i < 6; i++) {
            Rectangle colorBox = { 400 + (i * 50), 120, 40, 40 };
            DrawRectangleRec(colorBox, paddleColors[i]);
            if (CheckCollisionPointRec(GetMousePosition(), colorBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
            {
                paddleColor = paddleColors[i];
            }
        }
        
        DrawText("Ball Color:", 200, 180, 20, WHITE_TEXT);
        Color ballColors[] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW, WHITE, BLACK };
        for (int i = 0; i < 6; i++) {
            Rectangle colorBox = { 400 + (i * 50), 180, 40, 40 };
            DrawRectangleRec(colorBox, ballColors[i]);
            if (CheckCollisionPointRec(GetMousePosition(), colorBox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
            {
                ballColor = ballColors[i];
            }
        }
        
        DrawText("Music:", 200, 240, 20, WHITE_TEXT);
        Rectangle musicBar = { 400, 245, 200, 10 };
        DrawRectangleRec(musicBar, WHITE_TEXT);
        float musicSliderX = 400 + (musicVolume * 200);
        Rectangle musicSlider = { musicSliderX - 5, 240, 10, 20 };
        DrawRectangleRec(musicSlider, MY_DARK_PINK);
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), musicSlider)) 
        {
            isDraggingMusic = true;
        }
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && isDraggingMusic) 
        {
            musicVolume = (GetMousePosition().x - 400) / 200.0f;
            if (musicVolume < 0.0f) musicVolume = 0.0f;
            if (musicVolume > 1.0f) musicVolume = 1.0f;
            SetMusicVolume(gameMusic, musicVolume);
        }
        
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
        {
            isDraggingMusic = false;
        }
        
        DrawText("Sound Effects:", 200, 300, 20, WHITE_TEXT);
        Rectangle soundBar = { 400, 305, 200, 10 };
        DrawRectangleRec(soundBar, WHITE_TEXT);
        float soundSliderX = 400 + (soundVolume * 200);
        Rectangle soundSlider = { soundSliderX - 5, 300, 10, 20 };
        DrawRectangleRec(soundSlider, MY_DARK_PINK);
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), soundBar))
        {
            isDraggingSound = true;
        }
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && isDraggingSound) 
        {
            soundVolume = (GetMousePosition().x - 400) / 200.0f;
            if (soundVolume < 0.0f) soundVolume = 0.0f;
            if (soundVolume > 1.0f) soundVolume = 1.0f;
            SetSoundVolume(ballBounce, soundVolume);
        }
        
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
        {
            isDraggingSound = false;
        }

        // Tombol kembali
        Rectangle backBtn = { 300, 420, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(backBtn, "Back", MY_GREEN, MY_GREEN))
        {
            break;
        }
        
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
    if (musicVolume < 1.0f)
        musicVolume += 0.1f;
    SetMusicVolume(gameMusic, musicVolume);
}

void DecreaseVolume()
{
    if (musicVolume > 0.0f)
        musicVolume -= 0.1f;
    SetMusicVolume(gameMusic, musicVolume);
}

// void ToggleMute()
// {
//     isMuted = !isMuted;
//     SetMusicVolume(gameMusic, isMuted ? 0.0f : musicVolume);
// }

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
        return;  
    }

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK_BG);
        
        DrawText(message, 250, 100, 20, textColor);

        Rectangle backBtn = { 300, 300, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (DrawButton(backBtn, "Back", MY_YELLOW, MY_YELLOW))
        {
            return;  
        }

        EndDrawing();
    }
}

