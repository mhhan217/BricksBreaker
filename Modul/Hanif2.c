#include "Konfigurasi.h"
#include "Hanif.h"
//GAME

void updateGame(GameState *gameState,Difficulty* selectDifficult,int *selectNumber){
  switch(*gameState){
    case MENU: handleMenu(); break;
    case SETTINGS: handleSettings(); break;
    case INFO: handleInfo(); break;
    case LEVEL_SELECTION: handleLevelSelectionInput(gameState,selectDifficult,selectNumber); break;
    case PLAY: handlePlay(); break;
    case PAUSE: handlePause(); break;
    case EXIT: exit(0); break;
    default: break;  // Tambahan untuk menghindari kondisi tidak terduga
  }
}

void drawGame(GameState *gameState){
  switch(*gameState){
    case MENU: drawMenu(); break;
    case SETTINGS: drawSettings(); break;
    case INFO: drawInfo(); break;
    case LEVEL_SELECTION: drawLevelSelection(); break;
    case PLAY: drawPlay(); break;
    case PAUSE: drawPause(); break;
    case GAME_OVER: drawGameOver(); break;
    case EXIT: exit(0); break;
    default: break;  // Tambahan untuk menangani kondisi tidak valid
  }
}
