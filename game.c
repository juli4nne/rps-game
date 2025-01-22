#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int playGame(char* answer){
    // user input
    scanf("%9s", answer);
    // determines length for failsafe lowercasing
    int length = strlen(answer);

    // failsafe lowercasing
    for (int i = 0; i < length; i++){
        answer[i] = tolower(answer[i]);
    }

    // determine what answer is, return it in numerical value for convenience
    if (strcmp(answer, "rock") == 0){
        return 0;
    } else if (strcmp(answer, "paper") == 0)
    {
        return 1;
    } else if (strcmp(answer, "scissors") == 0)
    {
        return 2;
    } else {
        printf("\nInvalid answer.");
    }
}

void calculateAnswer(int result, int computer){
    if (computer == 0){
        printf("\nThe computer answered rock.");
        if (result == 0){
            printf("\nIt's a tie!");
        } else if (result == 1)
        {
            printf("\nYou win!");
        } else {
            printf("\nYou lose...");
        }
    } else if (computer == 1)
    {
        printf("\nThe computer answered paper.");
        if (result == 1){
            printf("\nIt's a tie!");
        } else if (result == 2)
        {
            printf("\nYou win!");
        } else {
            printf("\nYou lose...");
        }
    } else {
        printf("\nThe computer answered scissors.");
        if (result == 2){
            printf("\nIt's a tie!");
        } else if (result == 0)
        {
            printf("\nYou win!");
        } else {
            printf("\nYou lose...");
        }
    }
}

int main(){
    // declare variable and allocate dynamic memory
    char* answer;
    char playAgain;
    answer = (char*)malloc(10 * sizeof(char));
    
    // set random seed to current time
    srand(time(NULL));

    // console user interface
    printf("Welcome to Rock Paper Scissors. You will play against the computer.\nRock, Paper, Scissors: ");
    
    // receive answers from computer and user
    int result = playGame(answer);
    int computer = rand() % 3;
    printf("\nYou answered %s.", answer);

    // calculate results
    calculateAnswer(result, computer);

    // to do later
    /*printf("Do you want to play again? [Y/N]\n");
    scanf("%c", playAgain);*/

    // return 0
    return 0;
}