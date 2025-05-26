#include "../Include/Zahwa.h"
#include "../Include/Konfigurasi.h"
#include "raylib.h"
#define MAKS_NYAWA 3

// Paddle

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


//Lives

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
    if (lives->jumlah_nyawa > 0 && ball->Posisi.y + ball->Radius >= GetScreenHeight()) {
        lives->jumlah_nyawa--;  

        // Nyawa masih ada
        if (lives->jumlah_nyawa <= 0) {
            lives->jumlah_nyawa = 0;  
                
        }
    }
}

// Membersihkan memori texture lives icon
void UnloadLives(Lives* lives) {
    if (IsTextureValid(lives->heartIcon)) {
        UnloadTexture(lives->heartIcon);
        lives->heartIcon.id = 0;
    }
}

void displayMenu(ScreenControl *screen) {
    InitWindow(800, 600, "Bricks Breaker Menu"); 
    SetTargetFPS(60);
    InitAudioDevice();
    
    // Linked list menuOptions
    MenuNode *menuOptions = NULL;
    MenuNode *temp;
    
    // Node 1: "Play"
    menuOptions = (MenuNode*)malloc(sizeof(MenuNode));
    menuOptions->text = (char*)malloc(strlen("Play") + 1);
    strcpy(menuOptions->text, "Play");
    menuOptions->next = NULL;
    
    // Node 2: "Info"
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = (char*)malloc(strlen("Info") + 1);
    strcpy(temp->text, "Info");
    temp->next = NULL;
    menuOptions->next = temp;
    
    // Node 3: "Settings"
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = (char*)malloc(strlen("Settings") + 1);
    strcpy(temp->text, "Settings");
    temp->next = NULL;
    menuOptions->next->next = temp;
    
    // Node 4: "Exit"
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = (char*)malloc(strlen("Exit") + 1);
    strcpy(temp->text, "Exit");
    temp->next = NULL;
    menuOptions->next->next->next = temp;
    
    // Linked list highlightColors
    MenuNode *highlightColors = NULL;
    
    // Node 1: PINK
    highlightColors = (MenuNode*)malloc(sizeof(MenuNode));
    highlightColors->text = NULL;
    highlightColors->color = MY_DARK_PINK;
    highlightColors->next = NULL;
    
    // Node 2: BLUE
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = NULL;
    temp->color = MY_BLUE;
    temp->next = NULL;
    highlightColors->next = temp;
    
    // Node 3: GREEN
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = NULL;
    temp->color = MY_GREEN;
    temp->next = NULL;
    highlightColors->next->next = temp;
    
    // Node 4: YELLOW
    temp = (MenuNode*)malloc(sizeof(MenuNode));
    temp->text = NULL;
    temp->color = MY_YELLOW;
    temp->next = NULL;
    highlightColors->next->next->next = temp;
    
    int menuCount = 4;

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

        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
            screen->index = (screen->index + 1) % menuCount;
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
            screen->index = (screen->index - 1 + menuCount) % menuCount;

        // Menggambar menu menggunakan linked list
        MenuNode *currentMenu = menuOptions;
        MenuNode *currentHighlight = highlightColors;
        int i = 0;
        
        while (currentMenu != NULL && currentHighlight != NULL) {
            Color textColor = (i == screen->index) ? currentHighlight->color : WHITE;
            DrawText(currentMenu->text, SCREEN_WIDTH / 2 - textWidth / 2, 150 + (i * 60), 30, textColor);  
            
            currentMenu = currentMenu->next;
            currentHighlight = currentHighlight->next;
            i++;
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
            if (screen->index == 0) displayLevel(screen);
            else if (screen->index == 1) displayInfo(screen);
            else if (screen->index == 2) displaySettings(screen);
            else if (screen->index == 3) break;
        }

        EndDrawing();
    }
    
    // Membersihkan memori menuOptions
    MenuNode *current = menuOptions;
    while (current != NULL) {
        MenuNode *temp = current;
        current = current->next;
        if (temp->text != NULL) free(temp->text);
        free(temp);
    }
    
    // Membersihkan memori highlightColors
    current = highlightColors;
    while (current != NULL) {
        MenuNode *temp = current;
        current = current->next;
        free(temp);
    }
    
    CloseAudioDevice();
    CloseWindow();
}
