#include <string.h>  
#include "Faridha.h"

void InisialisasiLayarGameOver(LayarGameOver *layar) {
    strcpy(layar->pesan, "GAME OVER");  
    layar->lebarLayar = LEBAR_LAYAR;
    layar->tinggiLayar = TINGGI_LAYAR;
    layar->warnaTeks = RED;
}

void GambarLayarGameOver(LayarGameOver layar) {
    BeginDrawing();
    ClearBackground(BLACK);

    Color warnaHuruf[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, WHITE, PINK, SKYBLUE};
    
    const char *judulGame = "Bricks Breaker Game";
    int posisiXJudulGame = layar.lebarLayar / 2 - MeasureText(judulGame, 30) / 2;
    int posisiYJudulGame = layar.tinggiLayar / 6;
    int jarakHuruf = 5;
    
    for (int i = 0; i < strlen(judulGame); i++) {
        DrawText(TextFormat("%c", judulGame[i]), posisiXJudulGame, posisiYJudulGame, 30, warnaHuruf[i % (sizeof(warnaHuruf) / sizeof(warnaHuruf[0]))]);
        posisiXJudulGame += MeasureText(TextFormat("%c", judulGame[i]), 30) + jarakHuruf;
    }

    const char *judul = "GAME OVER";
    int posisiXJudul = layar.lebarLayar / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = layar.tinggiLayar / 4;
    DrawText(judul, posisiXJudul, posisiYJudul, 40, RED);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 - 60, 200, 40, PINK);
    DrawText("Score", layar.lebarLayar / 2 - MeasureText("Score", 20) / 2, layar.tinggiLayar / 2 - 50, 20, PINK);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 - 10, 200, 40, BLUE);
    DrawText("Restart", layar.lebarLayar / 2 - MeasureText("Restart", 20) / 2, layar.tinggiLayar / 2, 20, BLUE);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 + 40, 200, 40, GREEN);
    DrawText("Menu", layar.lebarLayar / 2 - MeasureText("Menu", 20) / 2, layar.tinggiLayar / 2 + 50, 20, GREEN);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 + 90, 200, 40, YELLOW);
    DrawText("Exit", layar.lebarLayar / 2 - MeasureText("Exit", 20) / 2, layar.tinggiLayar / 2 + 100, 20, YELLOW);

    EndDrawing();
}

void HapusLayarGameOver(LayarGameOver *layar) {
}
