#include <string.h>  
#include "Faridha.h"

int gameState = 0;

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

	int tombolX = layar.lebarLayar / 2 - 100;
    int tombolScoreY = layar.tinggiLayar / 2 - 60;

    DrawRectangleLines(tombolX, tombolScoreY, 200, 40, PINK);
    DrawText("Score", layar.lebarLayar / 2 - MeasureText("Score", 20) / 2, layar.tinggiLayar / 2 - 50, 20, PINK);

    if (CekKlikTombol(tombolX, tombolScoreY, 200, 40)) {
        gameState = 1; // Beralih ke layar skor
    }

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 - 10, 200, 40, BLUE);
    DrawText("Restart", layar.lebarLayar / 2 - MeasureText("Restart", 20) / 2, layar.tinggiLayar / 2, 20, BLUE);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 + 40, 200, 40, GREEN);
    DrawText("Menu", layar.lebarLayar / 2 - MeasureText("Menu", 20) / 2, layar.tinggiLayar / 2 + 50, 20, GREEN);

    DrawRectangleLines(layar.lebarLayar / 2 - 100, layar.tinggiLayar / 2 + 90, 200, 40, YELLOW);
    DrawText("Exit", layar.lebarLayar / 2 - MeasureText("Exit", 20) / 2, layar.tinggiLayar / 2 + 100, 20, YELLOW);

    EndDrawing();
}

void GambarLayarScore() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("SCORE", LEBAR_LAYAR / 2 - MeasureText("SCORE", 40) / 2, 100, 40, YELLOW);
    DrawText("Skor Anda: 1000", LEBAR_LAYAR / 2 - MeasureText("Skor Anda: 1000", 30) / 2, 200, 30, WHITE);

    int tombolKembaliX = LEBAR_LAYAR / 2 - 100;
    int tombolKembaliY = 400;

    DrawRectangleLines(tombolKembaliX, tombolKembaliY, 200, 40, RED);
    DrawText("Kembali", tombolKembaliX + 50, tombolKembaliY + 10, 20, RED);

    if (CekKlikTombol(tombolKembaliX, tombolKembaliY, 200, 40)) {
        gameState = 0; // Kembali ke layar Game Over
    }

    EndDrawing();
}

int CekKlikTombol(int x, int y, int lebar, int tinggi) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        return (mousePos.x >= x && mousePos.x <= x + lebar &&
                mousePos.y >= y && mousePos.y <= y + tinggi);
    }
    return 0;
}

void HapusLayarGameOver(LayarGameOver *layar) {
}
