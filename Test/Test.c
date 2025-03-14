#include "Billy.c"
#include "Hanif.c"

int main() {
    printf("Pilih tingkat kesulitan: 0 (Easy), 1 (Medium), 2 (Hard): ");
    int pilihan;
    scanf("%d", &pilihan);
    SetDifficulty(pilihan);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bricks Breaker");
    SetTargetFPS(TARGET_FPS);
    inisialisasibacksound();

    Ball bola;
    Paddle paddle;
    InitPaddle(&paddle, (Vector2){ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 30 }, (Vector2){ 100, 20 }, 15.0f);
    InitBall(&bola, (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, &paddle);
    inisialisasiBalok();

    while (!WindowShouldClose()) {
        bolaterkenabalok(&bola);
        UpdateBall(&bola, &paddle, (Vector2){0, -20});
        UpdatePaddle(&paddle);
        if (AreAllBricksDestroyed()) {
            NextLevel();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        gambarBalok();
        DrawBall(bola);
        DrawPaddle(paddle);
        EndDrawing();
    }
    
    tutupbacksound();
    CloseWindow();
    return 0;
}
