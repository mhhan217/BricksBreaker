#include <stdio.h>
#include "Chinta.h"
#include "raylib.h"

void displayMenu() 
{
    printf("=== Bricks Breaker Game ===\n");
    printf("1. Play\n");
    printf("Easy\n");
    printf("Medium\n");
    printf("Hard\n");
    printf("2. Info\n");
    printf("3. Leaderboard\n");
    printf("4. Exit\n");
}

void playGame() 
{
    int difficulty;
    printf("Level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty);

    while (difficulty < 1 || difficulty > 3) 
    {
        printf("Invalid choice. Please select a valid difficulty level.\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("Enter your choice: ");
        scanf("%d", &difficulty);
    }

    switch (difficulty) 
    {
        case 1:
            printf("Starting game on Easy difficulty...\n");
            // 75% lebih lambat
            // code to start on easy level
            break;
        case 2:
            printf("Starting game on Medium difficulty...\n");
            // kecapatan normal
            // code to start on medium level
            break;
        case 3:
            printf("Starting game on Hard difficulty...\n");
            // 25% lebih cepat
            // code to start on hard level
            break;
    }

    displayGameOverMenu();
}

void displayInfo() 
{
    printf("=== Game Info ===\n");
    printf("Power-ups: \n");
    printf("1. Extra Ball\n");
    printf("   If you get the Extra Ball power-up, you will have 3 balls in play.\n");
    printf("2. Larger Paddle\n");
    printf("   If you get the Larger Paddle power-up, your paddle will increase in size.\n");
    printf("3. Slow Ball\n");
    printf("   If you get the Slow Ball power-up, the ball will move slower.\n");
    printf("Levels: \n");
    printf("1. Easy: The ball moves more slowly.\n");
    printf("2. Medium: The ball moves at a normal speed.\n");
    printf("3. Hard: The /ball moves faster.\n");
}

void displayLeaderboard() 
{
    printf("=== Leaderboard ===\n");
    int scores[10];
    int count = loadScores(scores, 10); //Load skor dari history sebelumnya

    if (count == 0) 
    {
        printf("No scores available.\n");
    } 
    else 
    {
        printf("Highest Scores:\n");
        for (int i = 0; i < count; i++) 
        {
            char buffer[50];
            sprintf(buffer, "%d. %d\n", i + 1, scores[i]);
            printf(buffer);
        }
    }
}

int loadScores(int *scores, int maxScores) 
{
    FILE *file = fopen("scores.txt", "r");
    if (!file) 
    {
        return 0;
    }

    int count = 0;
    while (count < maxScores && fscanf(file, "%d", &scores[count]) == 1) 
    {
        count++;
    }

    fclose(file);
    return count;
}

void saveScore(int score) 
{
    FILE *file = fopen("scores.txt", "a");
    if (file) 
    {
        fprintf(file, "%d\n", score);
        fclose(file);
    }
}

void displayGameOverMenu() 
{
    int choice, finalscore;
    printf("=== Game Over ===\n");
    printf("1. Play Again\n");
    printf("2. Exit\n");
    printf("3. Score\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
	
    switch (choice) 
    {
        case 1:
            playGame();
            break;
        case 2:
            printf("Exiting the game..\n");
            break;
        case 3:
            //calculateFinalScore(); //Untuk menghitung skor akhir
            char buffer[50];
            //sprintf(buffer, "Final score: %d\n", finalScore);
            printf(buffer);
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
    }
}
void handleUserInput() 
{
    char choice;
    while (1) 
    {
        displayMenu();
        choice = getchar();
        getchar(); 

        switch (choice) 
        {
            case '1':
                playGame();
                break;
            case '2':
                displayInfo();
                break;
            case '3':
                displayLeaderboard();
                break;
            case '4':
                printf("Exiting the game..\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
