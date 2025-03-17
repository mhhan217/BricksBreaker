#include "raylib.h"
#include "Faridha.h"
#include "Konfigurasi.h"

Texture2D powerUpTexture;

int main() {
    // Inisialisasi jendela
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Layar Game Over");
    SetTargetFPS(TARGET_FPS);

	powerUpTexture = LoadTexture("assets/love.png"); // Sekarang dikenali

    PowerUp myPowerUp;
    InitializePowerUp(&myPowerUp);

    // Inisialisasi struktur game
    ScreenControl screenControl = {GAME_OVER, 0};
    LayarGameOver layarGameOver;
    InisialisasiLayarGameOver(&layarGameOver);
    

	
    while (!WindowShouldClose()) {
		UpdatePowerUp(&myPowerUp);


        BeginDrawing();
        ClearBackground(RAYWHITE);
		DrawPowerUp(myPowerUp);
        
        // Debugging - Menampilkan state saat ini di layar
        DrawText(TextFormat("GameState: %d", screenControl.gameState), 10, 10, 20, BLACK);
    	
        // Cek status game dan jalankan fungsi yang sesuai
        switch (screenControl.gameState) {
			case GAME_OVER:
			    HandleGameOverInput(&screenControl);
			    DrawGameOverScreen(&screenControl);
			    break;
			        
			case MENU:
			    break;
			
			case PLAYING:
			    break;
			
			case EXIT:
			    CloseWindow();
			    return 0;
			    break;
			
			    default:
			        break;

			
			}
			// Akhiri gambar untuk frame ini
			EndDrawing();

			// Jika game state adalah EXIT, hentikan loop utama
			if (screenControl.gameState == EXIT) {
				break;	

    		}
		}
		
    
	
	
	// Bersihkan sumber daya sebelum keluar
    HapusLayarGameOver(&layarGameOver);
	UnloadTexture(powerUpTexture);
	CloseWindow();

    return 0;
}