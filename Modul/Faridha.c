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

    Color warnaHuruf[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK, WHITE, SKYBLUE};

    const char *judul = "GAME OVER";
    int posisiXJudul = layar.lebarLayar / 2 - MeasureText(judul, 40) / 2;
    int posisiYJudul = layar.tinggiLayar / 4;
    int jarakHuruf = 5;

    for (int i = 0; i < strlen(judul); i++) {
        DrawText(TextFormat("%c", judul[i]), posisiXJudul, posisiYJudul, 40, warnaHuruf[i % (sizeof(warnaHuruf) / sizeof(warnaHuruf[0]))]);
        posisiXJudul += MeasureText(TextFormat("%c", judul[i]), 40) + jarakHuruf;
    }

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
