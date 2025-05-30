#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"
#include "../Include/Billy.h"
#include <stdio.h>
//SELECTED_LEVEL
int menuIndex = 0;
double lastInputTime = 0;
const double inputCooldown = 0.2;
// Fungsi untuk menangani input level
void handleLevelSelectionInput(GameState* gameState, Level* level,Ball* ball) {
    double currentTime = GetTime();
    if (currentTime - lastInputTime >= inputCooldown) {
        if (IsKeyPressed(KEY_UP)) {
            menuIndex = (menuIndex == 0) ? 3 : menuIndex - 1;
            panggilbacksound1();
            lastInputTime = currentTime;
        } else if (IsKeyPressed(KEY_DOWN)) {
            menuIndex = (menuIndex == 3) ? 0 : menuIndex + 1;
            panggilbacksound1();
            lastInputTime = currentTime;
        }
    }

    if (menuIndex == 0) {
        difficultLevel(level);//memanggil fungsi difficultlevel jika menu index=0
    }
    else if (menuIndex == 1) {
        numberLevel(level);//memanggil fungsi numberlevel jika menu index=1
    }
    else if (menuIndex == 2) {
        if (IsKeyPressed(KEY_ENTER)) {
            setSpeedBall(level, ball);//memanggil fungsi setspeedball jika menu index = 2 dan pengguna menekan enter

            *gameState = RESTART;
        }
    }
    else if (menuIndex == 3) {
        if (IsKeyPressed(KEY_ENTER)) {
            *gameState = MENU;//berpindah ke state menu jika pengguna menekan enter di menu index = 3
        }
    }
}
//fungsi untuk menangani input user jika berada di menu index = 0 atau memilih difficultlevel(easy,medium,hard)
void difficultLevel(Level *level) {
    if (IsKeyPressed(KEY_RIGHT)) level->DifficultLevel = (level->DifficultLevel == HARD) ? EASY : level->DifficultLevel + 1;
    if (IsKeyPressed(KEY_LEFT)) level->DifficultLevel = (level->DifficultLevel == EASY) ? HARD : level->DifficultLevel - 1;
}
//fungsi untuk menanganu input user jika berada di menu index = 1 atau memilih numberlevel(1-30)
int numberLevel(Level *level) {
    if (IsKeyPressed(KEY_RIGHT)) level->NumberLevel = (level->NumberLevel == 30) ? 1 : level->NumberLevel + 1;
    if (IsKeyPressed(KEY_LEFT)) level->NumberLevel = (level->NumberLevel == 1) ? 30 : level->NumberLevel - 1;

    return level->NumberLevel - 1;
}

// void drawLevel(Level *level) {
//     ClearBackground(BLACK);

//     // Judul
//     DrawText("SELECT LEVEL", 200, 50, 30, WHITE);

//     // Warna untuk highlight menu yang dipilih
//     Color colors[4] = {WHITE, WHITE, WHITE, WHITE};
//     colors[menuIndex] = YELLOW;  // Highlight menu yang dipilih

//     // Array untuk teks menu
//     char difficultyText[10];
//     sprintf(difficultyText, "%s", (level->DifficultLevel == EASY) ? "EASY" : (level->DifficultLevel == MEDIUM) ? "MEDIUM" : "HARD");

//     char levelText[10];
//     sprintf(levelText, "LEVEL %d", level->NumberLevel);

//     // Menampilkan menu vertikal
//     DrawText(difficultyText, 100, 150, 20, colors[0]);
//     DrawText(levelText, 100, 200, 20, colors[1]);
//     DrawText("START", 100, 250, 20, colors[2]);
//     DrawText("BACK", 100, 300, 20, colors[3]);
// }
