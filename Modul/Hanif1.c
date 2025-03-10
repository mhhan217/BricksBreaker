#include "../Include/Hanif.h"
#include "../Include/Konfigurasi.h"
//SELECTED_LEVEL

// Fungsi untuk menangani input level
void handleLevelSelectionInput(GameState *gameState, Difficulty *selectDifficult, int *selectNumber) {
  int menuIndex = 0;  
  // mengahandle pemilihan menu
    if (IsKeyPressed(KEY_UP)) {
        (menuIndex)--;
    } 
    else if (IsKeyPressed(KEY_DOWN)) {
        (menuIndex)++;
    }
    // untuk membatasi menuindex 0-3 saja
    if (menuIndex < 0) {
        menuIndex = 3;
    } else if (menuIndex > 3) {
        menuIndex = 0;
    }

    //untuk menentukan menu index yang dipilih
    switch(menuIndex) {
        case 0: 
            difficultLevel(selectDifficult);
            break;

        case 1: 
            numberLevel(selectNumber);
            break;

        case 2: 
            if (IsKeyPressed(KEY_ENTER)) {  
                *gameState = LOADING;  
            }
            break;

        case 3: 
            if (IsKeyPressed(KEY_ENTER)) {  
                *gameState = MENU;  
            }
            break;
    }
}

// Fungsi untuk memilih tingkat kesulitan
void difficultLevel(Difficulty *selectDifficulty) {
    if (IsKeyPressed(KEY_RIGHT)) {
        (*selectDifficulty)++;
    } else if (IsKeyPressed(KEY_LEFT)) {
        (*selectDifficulty)--;
    }

    // untuk membatasi kesuliatan 0-2 (easy-hard)
    if (*selectDifficulty > 2) {
        *selectDifficulty = 0;
    } else if (*selectDifficulty < 0) {
        *selectDifficulty = 2;
    }
}

// fungsi untuk menentukan nomor level yang dipilih
void numberLevel(int *selectNumber) {
    if (IsKeyPressed(KEY_RIGHT)) {
        (*selectNumber)++;
    } else if (IsKeyPressed(KEY_LEFT)) {
        (*selectNumber)--;
    }

    // untuk membatasi level 1-30 saja
    if (*selectNumber > 30) {
        *selectNumber = 1;
    } else if (*selectNumber < 1) {
        *selectNumber = 30;
    }
}

// Fungsi untuk mendapatkan level yang dipilih
int getSelectNumber(int selectNumber) {
    return selectNumber;
}

// Fungsi untuk mendapatkan tingkat kesulitan yang dipilih
Difficulty getSelectDifficulty(Difficulty selectDifficult) {
    return selectDifficult;
}
