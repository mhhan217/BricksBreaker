#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../Include/Zahwa.h"
#include "../Include/Chinta.h"
#include "../Include/Billy.h"

#define MAKS_NYAWA 3

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan) {
    Paddle->Posisi = posisiAwal;
    Paddle->Ukuran = ukuran;
    Paddle->Kecepatan = kecepatan;
    Paddle->Warna = RAYWHITE;
}

void UpdatePaddle(Paddle* Paddle) {
    if (IsKeyDown(KEY_LEFT) && Paddle->Posisi.x > 0) {
        Paddle->Posisi.x -= Paddle->Kecepatan;
    }
    if (IsKeyDown(KEY_RIGHT) && Paddle->Posisi.x + Paddle->Ukuran.x < GetScreenWidth()) {
        Paddle->Posisi.x += Paddle->Kecepatan;
    }

}

void DrawPaddle(Paddle Paddle) {
    DrawRectangleV(Paddle.Posisi, Paddle.Ukuran, Paddle.Warna);
}

void InitLives(Lives* lives, Vector2 Posisi) {
    lives->jumlah_nyawa = MAKS_NYAWA;
    lives->posisi = (Vector2){0, 0};  // Posisi ikon nyawa di pojok kiri atas
    lives->heartIcon = LoadTexture("HeartPixel.png");
    if (!IsTextureValid(lives->heartIcon)) {
        TraceLog(LOG_ERROR, "Gagal memuat HeartPixel.png"); // Jika file tidak ditemukan
    }
}

void DrawLives(Lives* lives) {
    if (IsTextureValid(lives->heartIcon)) {
        int jarak = 2;
        for (int i = 0; i < lives->jumlah_nyawa; i++) {
            DrawTexture(lives->heartIcon,
                    lives->posisi.x + (i * (lives->heartIcon.width + jarak)),
                    lives->posisi.y, WHITE);
        }
    } 
}

void UpdateLives(Lives* lives, Ball* ball) {
    // Cek bola jatuh ke bawah layar 
    if (lives->jumlah_nyawa > 0 && ball->Position.y + ball->Radius >= GetScreenHeight()) {
        lives->jumlah_nyawa--;  
        // Nyawa masih ada
        if (lives->jumlah_nyawa <= 0) {
            lives->jumlah_nyawa = 0;          
        }
    }
}    

// Cleanup memory texture lives icon setelah permainan selesai
void UnloadLives(Lives* lives) {
    if (IsTextureValid(lives->heartIcon)) {
        UnloadTexture(lives->heartIcon);
        lives->heartIcon.id = 0;
    }
}

// convert Array to SLL
void displayMenuWithGraphics() {
    InitWindow(600, 800, "Bricks Breaker Menu");
    SetTargetFPS(60);
    
    // Membuat linked list per node menu
    MenuNode* menuHead = NULL;
    
    // Node Play
    MenuNode* node1 = (MenuNode*)malloc(sizeof(MenuNode));
    node1->menumenuOption = "Play";
    node1->highlightColor = MY_DARK_PINK;
    node1->next = NULL;
    menuHead = node1;
    
    // Node Info
    MenuNode* node2 = (MenuNode*)malloc(sizeof(MenuNode));
    node2->menuOption = "Info";
    node2->highlightColor = MY_BLUE;
    node2->next = NULL;
    node1->next = node2;
    
    // Node Settings
    MenuNode* node3 = (MenuNode*)malloc(sizeof(MenuNode));
    node3->menuOption = "Settings";
    node3->highlightColor = MY_GREEN;
    node3->next = NULL;
    node2->next = node3;
    
    // Node Exit
    MenuNode* node4 = (MenuNode*)malloc(sizeof(MenuNode));
    node4->menuOption = "Exit";
    node4->highlightColor = MY_YELLOW;
    node4->next = NULL;
    node3->next = node4;
    
    int menuCount = 4;
    
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

        int selectedMenuOption = 0;
        
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
            panggilbacksound1();
            selectedMenuOption = (selectedMenuOption + 1) % menuCount;
        }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
            panggilbacksound1();
            selectedMenuOption = (selectedMenuOption - 1 + menuCount) % menuCount;
        }
        
        MenuNode* current = menuHead;
        int index = 0;
        while (current != NULL) {
            Color textColor = (index == selectedMenuOption) ? current->highlightColor : WHITE;
            int textWidth = MeasureText(current->menuOption, 30);
            DrawText(current->menuOption, SCREEN_WIDTH / 2 - textWidth / 2, 150 + (index * 60), 30, textColor);
            
            current = current->next;
            index++;
        }
        
        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            if (selectedMenuOption == 0) break;
            else if (selectedMenuOption == 1) displayInfo();
            else if (selectedMenuOption == 2) displaySettings();
            else if (selectedMenuOption == 3) break;
        }
        
        EndDrawing();
    }
    
    // Cleanup memory
    while (menuHead != NULL) {
        MenuNode* temp = menuHead;
        menuHead = menuHead->next;
        free(temp);
    }
    
    CloseWindow();
}