
#ifndef CHINTA_H
#define CHINTA_H
#include "konfigurasi.h"

void displayMenu();
void playGame();
void displayInfo();
void displayLeaderboard();
int loadScores();
void saveScores();
void displayGameOverMenu();
int calculateFinalScore();
void handleUserInput();
void drawText(const char* text);

#endif //CHINTA_H
