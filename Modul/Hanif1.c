#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"
//SELECTED_LEVEL

// Fungsi untuk menangani input level
void handleLevelSelectionInput(ScreenControl* screen, Level *level,Ball* ball) {
    //membatasi pilihan pada menu index
    if (IsKeyPressed(KEY_UP)) {
        screen->index= (screen->index== 0) ? 3 : screen->index- 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        screen->index= (screen->index== 3) ? 0 : screen->index+ 1;
    }

    if (screen->index== 0) {
        difficultLevel(level);//memanggil fungsi difficultlevel jika menu index=0
    }
    else if (screen->index== 1) {
        numberLevel(level);//memanggil fungsi numberlevel jika menu index=1
    }
    else if (screen->index== 2) {
        if (IsKeyPressed(KEY_ENTER)) {
            setSpeedBall(ball,level);//memanggil fungsi setspeedball jika menu index = 2 dan pengguna menekan enter

            screen->gameState = LOADING;//berpindah ke state loading
        }
    }
    else if (screen->index== 3) {
        if (IsKeyPressed(KEY_ENTER)) {
            screen->gameState = MENU;//berpindah ke state menu jika pengguna menekan enter di menu index = 3
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

