#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void calculate_score(int user_score, int comp_score);

int main()
{
    int user_choice, user_score = 0, comp_score = 0;
    char play_again;
    char choice_name[3][10] = {"Rock", "Paper", "Scissor"};

    printf("\n Welcome to the Rock paper scissors game \n \t'Developed by Arqam'\n");
    sleep(1);

    while (1)
    {
        printf("Choices: \n1.Rock \n2.Paper \n3.Scissor\n");

        printf("\nEnter your choice please: ");
        scanf("%d", &user_choice);

        while (user_choice > 3 || user_choice < 1)
        {
            printf("Enter a valid choice please: ");
            scanf("%d", &user_choice);
        }
        if (user_choice == 1)
        {
            printf("User choice is: %s\n", choice_name[0]);
        }
        else if (user_choice == 2)
        {
            printf("User Choice is: %s\n", choice_name[1]);
        }
        else
        {
            printf("User Choice is: %s\n", choice_name[2]);
        }

        printf("\nNow its Computers Turn....\n");
        sleep(3);

        srand(time(NULL));
        int comp_choice = rand() % 3 + 1;

        printf("\nComputer Choice is: %d\n", comp_choice);
        sleep(2);

        if (comp_choice == 1)
        {
            printf("Computer choice is: %s\n", choice_name[0]);
        }
        else if (comp_choice == 2)
        {
            printf("Computer Choice is: %s\n", choice_name[1]);
        }
        else
        {
            printf("Computer Choice is: %s\n", choice_name[2]);
        }
        sleep(3);

        if (user_choice == comp_choice)
        {
            printf("\n<== Its a Draw ==>\n");
        }
        else if ((user_choice == 1 && comp_choice == 2) || (user_choice == 2 && comp_choice == 3) || (user_choice == 3 && comp_choice == 1))
        {
            printf("\n<== Computer wins ==>\n");
            comp_score++;
        }
        else
        {
            printf("\n<== User wins ==>\n");
            user_score++;
        }

        calculate_score(user_score, comp_score);

        sleep(5);

        printf("\nDo you want to play again? (Y/N)\n");
        scanf(" %c", &play_again);

        printf("\n");

        if (play_again == 'n' || play_again == 'N')
        {
            sleep(1);
            printf("\nThanks For Playing :) ");
            printf("\nYour Score: %d\n", user_score);
            printf("Computer's Score: %d\n", comp_score);
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}

void calculate_score(int user_score, int comp_score)
{
    printf("\nCurrent Score - User: %d, Computer: %d\n", user_score, comp_score);
}
