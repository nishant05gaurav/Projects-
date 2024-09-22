#include <stdio.h>
#include <stdlib.h>

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player1[15], player2[15];
int count = 0;

void box()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("||");
        for (j = 0; j < 3; j++)
        {
            printf(" %c ||", matrix[i][j]);
        }
        printf("\n||---||---||---||\n");
    }
}

char win()
{
    int i;
    // Row and column checks
    for (i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) // Row check
            return matrix[i][0];
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) // Column check
            return matrix[0][i];
    }
    // Diagonal checks
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) // Diagonal-1
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) // Diagonal-2
        return matrix[0][2];

    return '$';
}

void input()
{
    int i, j;
    char n, a;

    while (1)
    {
        printf("\n\n\nTurn for %s....\n", player1);
        count++;
        scanf(" %c", &n);
        fflush(stdin);

        int validMove = 0; // To check if the move is valid
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (n == matrix[i][j])
                {
                    if (count % 2 == 0)
                        matrix[i][j] = 'O';
                    else
                        matrix[i][j] = 'X';
                    validMove = 1;
                }
            }
        }

        // Asking again, if the move is invalid
        if (!validMove)
        {
            printf("Invalid move, try again.\n");
            count--;
            continue;
        }

        system("cls");
        box();
        a = win();

        // Check for a winner or tie
        if (a == 'X')
        {
            printf("\n\nCongratulation %s! You have won the game!!!!", player1);
            count = 0;
            break;
        }
        else if (a == '$' && count == 9)
        {
            printf("\n\n\n\tIt's a tie!!!!!");
            count = 0;
            break;
        }

        printf("\n\n\nTurn for %s....\n", player2);
        count++;
        scanf(" %c", &n);
        fflush(stdin);

        validMove = 0; // Reset for player 2's move
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (n == matrix[i][j])
                {
                    if (count % 2 == 0)
                        matrix[i][j] = 'O';
                    else
                        matrix[i][j] = 'X';
                    validMove = 1;
                }
            }
        }

        // Asking again, if player 2's move was invalid
        if (!validMove)
        {
            printf("Invalid move, try again.\n");
            count--;
            continue;
        }

        system("cls");
        box();
        a = win();
        if (a == 'O')
        {
            printf("\n\n\n\tCongratulation %s! You have won the game!!!!", player2);
            break;
        }
    }
}

int main()
{
    system("Color 3F");
    int choice;

Label1:
    system("cls");
    printf("\n1. Start the game.");
    printf("\n2. How to play?");
    printf("\n3. Quit the game.");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fflush(stdin);
        system("cls");
        printf("\nEnter player's name who is choosing 'X': ");
        fflush(stdin);
        gets(player1);
        printf("\nWelcome %s! Your icon is 'X'.", player1);

        printf("\nEnter player's name who is choosing 'O': ");
        fflush(stdin);
        gets(player2);
        printf("\nWelcome %s! Your icon is 'O'.", player2);

        system("pause");
        system("cls");
        box();
        input();
        printf("\n\n\n\t\t\t\tGAME OVER\n");
        system("pause");
        goto Label1;
        break;

    case 2:
        system("cls");
        printf("\n\n\t\t\t\t:_INSTRUCTIONS:_\n");
        printf("\n\tThe game is played on a grid that's 3 squares by 3 squares.\n");
        printf("\tYou are X, your friend is O. Players take turns putting their marks in empty squares.\n");
        printf("\tThe first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
        printf("\tWhen all 9 squares are full, the game is over.\n\n\t\t\t");
        system("pause");
        goto Label1;
        break;

    case 3:
        exit(1);
        break;

    default:
        printf("\nInvalid Choice\n");
    }
}