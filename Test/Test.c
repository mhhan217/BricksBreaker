
#include "raylib.h"
#include "../Modul/Zahwa.c"
#include "../Include/Konfigurasi.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BricksBreaker");

    displayMenuWithGraphics();

    CloseWindow();

    return 0;
}
