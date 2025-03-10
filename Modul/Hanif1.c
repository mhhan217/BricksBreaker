#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"
//SELECTED_LEVEL

// Fungsi untuk menangani input level
void handleLevelSelectionInput(GameState *gameState, Level *level,Ball* ball) {
    static int menuIndex = 0;
    //membatasi pilihan pada menu index
    if (IsKeyPressed(KEY_UP)) {
        menuIndex = (menuIndex == 0) ? 3 : menuIndex - 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        menuIndex = (menuIndex == 3) ? 0 : menuIndex + 1;
    }

    if (menuIndex == 0) {
        difficultLevel(level);//memanggil fungsi difficultlevel jika menu index=0
    }
    else if (menuIndex == 1) {
        numberLevel(level);//memanggil fungsi numberlevel jika menu index=1
    }
    else if (menuIndex == 2) {
        if (IsKeyPressed(KEY_ENTER)) {
            setSpeedBall(ball,level);//memanggil fungsi setspeedball jika menu index = 2 dan pengguna menekan enter

            *gameState = LOADING;//berpindah ke state loading
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
void numberLevel(Level *level) {
    if (IsKeyPressed(KEY_RIGHT)) level->NumberLevel = (level->NumberLevel == 30) ? 1 : level->NumberLevel + 1;
    if (IsKeyPressed(KEY_LEFT)) level->NumberLevel = (level->NumberLevel == 1) ? 30 : level->NumberLevel - 1;
}

