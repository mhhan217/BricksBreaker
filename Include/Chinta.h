#ifndef CHINTA_H
#define CHINTA_H

#include <stdio.h>
#include "raylib.h"

typedef struct MenuTextNode {
    char text[50];
    struct MenuTextNode *next;
} MenuTextNode;

typedef struct ColorNode {
    Color color;
    struct ColorNode *next;
} ColorNode;

extern float musicVolume;
extern float soundVolume;
extern Sound ballBounce;
extern Music gameMusic;

// Deklarasi fungsi
void displayMenu(ScreenControl *screen);
void displayLevel(ScreenControl *screen);
void displayInfo(ScreenControl *screen);
void displaySettings(ScreenControl *screen);
void IncreaseVolume();
void DecreaseVolume();
void IncreaseSound();
void DecreaseSound();
void displayPause(ScreenControl *screen);

void appendMenuText(MenuTextNode **head, const char *text);
MenuTextNode* getMenuTextNodeAt(MenuTextNode *head, int index);

void appendColor(ColorNode **head, Color color);

#endif // CHINTA_H