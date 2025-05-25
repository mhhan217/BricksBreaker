#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
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

int currentDifficulty = 0;
int selectedLevel = 1;
float musicVolume = 1.0f;
float soundVolume = 1.0f;

Sound ballBounce;
Music gameMusic;

Level level;
Ball ball;

void displayMenu(ScreenControl *screen) {
    InitWindow(600, 800, "Bricks Breaker Menu");
    SetTargetFPS(60);
    InitAudioDevice();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        DrawText("B", 120, 50, 30, MY_DARK_PINK);
        DrawText("r", 140, 50, 30, MY_BLUE);
        DrawText("i", 160, 50, 30, MY_GREEN);
        DrawText("c", 180, 50, 30, MY_YELLOW);
        DrawText("k", 200, 50, 30, MY_DARK_PINK);
        DrawText("s", 220, 50, 30, MY_BLUE);
        DrawText(" ", 240, 50, 30, MY_GREEN);
        DrawText("B", 260, 50, 30, MY_YELLOW);
        DrawText("r", 280, 50, 30, MY_DARK_PINK);
        DrawText("e", 300, 50, 30, MY_BLUE);
        DrawText("a", 320, 50, 30, MY_GREEN);
        DrawText("k", 340, 50, 30, MY_YELLOW);
        DrawText("e", 360, 50, 30, MY_DARK_PINK);
        DrawText("r", 380, 50, 30, MY_BLUE);
        DrawText(" ", 400, 50, 30, MY_GREEN);
        DrawText("G", 420, 50, 30, MY_YELLOW);
        DrawText("a", 440, 50, 30, MY_DARK_PINK);
        DrawText("m", 460, 50, 30, MY_BLUE);
        DrawText("e", 480, 50, 30, MY_GREEN);

        const char *menuOptions[] = { "Play", "Info", "Settings", "Exit" };
        Color highlightColors[] = { MY_DARK_PINK, MY_BLUE, MY_GREEN, MY_YELLOW };
        int menuCount = 4;

        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
            screen->index = (screen->index + 1) % menuCount;
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
            screen->index = (screen->index - 1 + menuCount) % menuCount;

        for (int i = 0; i < menuCount; i++) {
            Color textColor = (i == screen->index) ? highlightColors[i] : WHITE;
            int textWidth = MeasureText(menuOptions[i], 30);
            DrawText(menuOptions[i], SCREEN_WIDTH / 2 - textWidth / 2, 150 + (i * 60), 30, textColor);
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
    MenuTextNode *difficultyList = NULL;
    appendMenuText(&difficultyList, "EASY");
    appendMenuText(&difficultyList, "MEDIUM");
    appendMenuText(&difficultyList, "HARD");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK_BG);

        // Judul dengan warna berbeda
        DrawText("P", 130, 50, 30, MY_DARK_PINK);
        DrawText("I", 150, 50, 30, MY_BLUE);
        DrawText("L", 170, 50, 30, MY_GREEN);
        DrawText("I", 190, 50, 30, MY_YELLOW);
        DrawText("H", 210, 50, 30, MY_DARK_PINK);
        DrawText(" ", 230, 50, 30, MY_BLUE);
        DrawText("L", 250, 50, 30, MY_GREEN);
        DrawText("E", 270, 50, 30, MY_YELLOW);
        DrawText("V", 290, 50, 30, MY_DARK_PINK);
        DrawText("E", 310, 50, 30, MY_BLUE);
        DrawText("L", 330, 50, 30, MY_GREEN);

        // Opsi kesulitan
        MenuTextNode *diffNode = getMenuTextNodeAt(difficultyList, level.DifficultLevel);
        const char *difficultyText = (diffNode != NULL) ? diffNode->text : "UNKNOWN";
        Color difficultyColor = (screen->index == 0) ? MY_DARK_PINK : WHITE;
        int diffWidth = MeasureText(difficultyText, 30);
        DrawText(difficultyText, SCREEN_WIDTH / 2 - diffWidth / 2, 150, 30, difficultyColor);

        // Opsi pemilihan level
        char levelText[20];
        sprintf(levelText, "LEVEL %d", level.NumberLevel);
        Color levelColor = (screen->index == 1) ? MY_BLUE : WHITE;
        int levelWidth = MeasureText(levelText, 30);
        DrawText(levelText, SCREEN_WIDTH / 2 - levelWidth / 2, 250, 30, levelColor);

        // Opsi start game
        Color startColor = (screen->index == 2) ? MY_GREEN : WHITE;
        int startWidth = MeasureText("START GAME", 30);
        DrawText("START GAME", SCREEN_WIDTH / 2 - startWidth / 2, 350, 30, startColor);

        // Opsi kembali
        Color backColor = (screen->index == 3) ? MY_YELLOW : WHITE;
        int backWidth = MeasureText("BACK", 30);
        DrawText("BACK", SCREEN_WIDTH / 2 - backWidth / 2, 450, 30, backColor);

        handleLevelSelectionInput(screen, &level, &ball);

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
        DrawText("P", 250, 100, 30, MY_BLUE);
        DrawText("o", 280, 100, 30, MY_GREEN);
        DrawText("w", 300, 100, 30, MY_YELLOW);
        DrawText("e", 320, 100, 30, MY_DARK_PINK);
        DrawText("r", 340, 100, 30, MY_BLUE);
        DrawText("-", 360, 100, 30, MY_GREEN);
        DrawText("u", 380, 100, 30, MY_YELLOW);
        DrawText("p", 400, 100, 30, MY_DARK_PINK);

        // Isi halaman
        DrawText("1. Pemain memiliki 3 nyawa di awal permainan.", 100, 175, 20, WHITE_TEXT);
        DrawText("2. Jika bola jatuh lebih dari 4 kali, permainan berakhir (Game Over).", 100, 225, 20, WHITE_TEXT);
        DrawText("3. Pemain akan menang jika semua balok berhasil dihancurkan.", 100, 275, 20, WHITE_TEXT);

        DrawText("Press B to go back", 200, 350, 20, MY_YELLOW);

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
        DrawText("S", 220, 50, 30, MY_BLUE);
        DrawText("e", 240, 50, 30, MY_GREEN);
        DrawText("t", 260, 50, 30, MY_YELLOW);
        DrawText("t", 280, 50, 30, MY_DARK_PINK);
        DrawText("i", 300, 50, 30, MY_BLUE);
        DrawText("n", 320, 50, 30, MY_GREEN);
        DrawText("g", 340, 50, 30, MY_YELLOW);
        DrawText("s", 360, 50, 30, MY_DARK_PINK);

        // Music Volume
        DrawText("Music Volume:", 230, 240, 20, WHITE);
        DrawRectangle(400, 245, 200, 10, GRAY); 
        DrawRectangle(400, 245, (int)(musicVolume * 200), 10, MY_GREEN); 
        DrawText(TextFormat("%d", (int)(musicVolume * 100)), 610, 240, 20, YELLOW);

        // Sound Effects
        DrawText("Sound Effects:", 220, 300, 20, WHITE);
        DrawRectangle(400, 305, 200, 10, GRAY);
        DrawRectangle(400, 305, (int)(soundVolume * 200), 10, MY_YELLOW);
        DrawText(TextFormat("%d", (int)(soundVolume * 100)), 610, 300, 20, YELLOW);

        // Back to Menu
        DrawText("Press B to go back", 200, 400, 20, MY_GREEN);

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

    MenuTextNode *pauseMenu = NULL;
    appendMenuText(&pauseMenu, "Resume");
    appendMenuText(&pauseMenu, "Settings");
    appendMenuText(&pauseMenu, "Restart");
    appendMenuText(&pauseMenu, "Menu");

    ColorNode *pauseColors = NULL;
    appendColor(&pauseColors, MY_DARK_PINK);
    appendColor(&pauseColors, MY_BLUE);
    appendColor(&pauseColors, MY_GREEN);
    appendColor(&pauseColors, MY_YELLOW);

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
        DrawText("P", 225, 50, 40, MY_BLUE);
        DrawText("A", 250, 50, 40, MY_GREEN);
        DrawText("U", 275, 50, 40, MY_YELLOW);
        DrawText("S", 300, 50, 40, MY_DARK_PINK);
        DrawText("E", 325, 50, 40, MY_BLUE);
        DrawText("D", 350, 50, 40, MY_GREEN);

        // Menu pause
        MenuTextNode *textNode = pauseMenu;
        ColorNode *colorNode = pauseColors;
        for (int i = 0; i < menuCount; i++) {
            int x = SCREEN_WIDTH / 2 - MeasureText(textNode->text, 30) / 2;
            int y = 150 + (i * 60);
            Color color = (i == screen->index) ? colorNode->color : WHITE;
            DrawText(textNode->text, x, y, 30, color);
            textNode = textNode->next;
            colorNode = colorNode->next;
        }

        EndDrawing();
    }
}

void appendMenuText(MenuTextNode **head, const char *text) {
    MenuTextNode *newNode = malloc(sizeof(MenuTextNode));
    strcpy(newNode->text, text);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        MenuTextNode *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

MenuTextNode* getMenuTextNodeAt(MenuTextNode *head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}

void appendColor(ColorNode **head, Color color) {
    ColorNode *newNode = malloc(sizeof(ColorNode));
    newNode->color = color;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ColorNode *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}