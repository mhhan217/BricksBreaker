#include "../Include/Konfigurasi.h"
#include "../Include/Hanif.h"
#include "../Include/Faridha.h"
#include "../Include/Zahwa.h"
#include "../Include/Billy.h"
//GAME

void updateGame(ScreenControl* screen,Difficulty* selectDifficult,int *selectNumber){
  switch(screen->gameState){
    case MENU: handleMenu(); break;
    case SETTINGS: handleSettings(); break;
    case INFO: handleInfo(); break;
    case LEVEL_SELECTION: handleLevelSelectionInput(selectDifficult,selectNumber); break;
    case PLAY: handlePlay(); break;
    case PAUSE: handlePause(); break;
    case EXIT: exit(0);
    default: break;  // Tambahan untuk menghindari kondisi tidak terduga
  }
}

void drawGame(ScreenControl* screen){
  switch(screen->gameState){
    case MENU: drawMenu(); break;
    case SETTINGS: drawSettings(); break;
    case INFO: drawInfo(); break;
    case LEVEL_SELECTION: drawLevelSelection(); break;
    case PLAY: drawPlay(); break;
    case PAUSE: drawPause(); break;
    case GAME_OVER: drawGameOver(); break;
    case EXIT: exit(0);
    default: break;  // Tambahan untuk menangani kondisi tidak valid
  }
}
