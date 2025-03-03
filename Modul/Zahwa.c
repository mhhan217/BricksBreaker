#include "raylib.h"
#include "zahwa.h"

void InitPaddle(Paddle* Paddle, Vector2 posisiAwal, Vector2 ukuran, float kecepatan) {
    Paddle->Posisi = posisiAwal;
    Paddle->Ukuran = ukuran;
    Paddle->Kecepatan = kecepatan;
    Paddle->Warna = RAYWHITE;
}

void UpdatePaddle(Paddle* Paddle) {
    if (IsKeyDown(KEY_LEFT) && Paddle->Posisi.x > 0) {
        Paddle->Posisi.x -= Paddle->Kecepatan;
    }
    if (IsKeyDown(KEY_RIGHT) && Paddle->Posisi.x + Paddle->Ukuran.x < GetScreenWidth()) {
        Paddle->Posisi.x += Paddle->Kecepatan;
    }
	// Jika tombol UP ditekan, perbesar paddle
    if (IsKeyPressed(KEY_UP)) {
        Paddle->Ukuran.x += 10;  // Tambah panjang paddle
    }
    // Jika tombol DOWN ditekan, perkecil paddle
    if (IsKeyPressed(KEY_DOWN) && Paddle->Ukuran.x > 20) {
        Paddle->Ukuran.x -= 10;  // Kurangi panjang paddle
    }
    if (IsKeyPressed(KEY_SPACE)) {
        Paddle->Warna = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 }; //ubah random warna paddle dengan space
    }
}

void DrawPaddle(Paddle Paddle) {
    DrawRectangleV(Paddle.Posisi, Paddle.Ukuran, Paddle.Warna);
}
