#include "Billy.c"
#include "Hanif.c"
#include "Chinta.c"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);
    displayMenuWithGraphics();
    CloseWindow();
}
