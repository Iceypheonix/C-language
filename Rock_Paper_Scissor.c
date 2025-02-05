#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int player;
    int computer = rand() % 3;

    printf("Enter by player 0 for Rock 1 for Paper and 2 for Scissor \n");
    scanf("%d", &player);

    printf("Chosen by computer 0 for Rock 1 for Paper and 2 for Scissor");
    printf(" \n %d \n", computer);

    if (player == 0 && computer == 0)
    {
        printf("Match draw play again");
    }
    else if (player == 0 && computer == 1)
    {
        printf("you lose");
    }
    else if (player == 0 && computer == 2)
    {
        printf("you win");
    }
    else if (player == 1 && computer == 1)
    {
        printf("Match draw play again");
    }
    else if (player == 1 && computer == 0)
    {
        printf("you win");
    }
    else if (player == 1 && computer == 2)
    {
        printf("you lose");
    }
    else if (player == 2 && computer == 2)
    {
        printf("Match draw play again");
    }
    else if (player == 2 && computer == 1)
    {
        printf("you win");
    }
    else if (player == 2 && computer == 0)
    {
        printf("you lose");
    }
    else 
        {
            printf("You enter wrong number");
        }
    return 0;
}