#include <stdio.h>
#include <stdlib.h>

char player1;
char player2;
char game[9];
int turn;
int mode;

int main()
{
    turn = 0;
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        game[i] = ' ';
    }
    int n = gameMode();
    int choice = displayMenu();
    letsPlay();
}

void letsPlay()
{
    int i = 0;
    for(i=0; i<9; i++)
    {
        displayBoard();
        if (i > 4)
        {
            if(checkWinner() == 1)
            {
                if(turn == 0 && mode == 1)
                {
                    printf("\n\n\tComputer WINS!!!\n\n");
                    main();
                    break;
                }
                else if(turn == 0 && mode == 0)
                {
                    printf("\n\n\t\tPlayer 2 WINS!!!\n\n");
                    main();
                    break;
                }
                else
                {
                    printf("\n\n\t\tPlayer 1 WINS!!!\n\n");
                    main();
                    break;
                }
            }
        }
        if(turn == 0)
        {
            humanTurn();
        }
        else if(turn == 1)
        {

            if(mode == 1)
            {
                computerTurn();
            }
            else if (mode == 0)
            {
                player2Turn();
            }
        }

    }

    if(i==9 && checkWinner() == 0)
    {
        displayBoard();
        printf("\n\n\tGame DRAW!!!\n\n");
        main();
    }

}

int humanTurn()
{
    int n;
    printf("\nPlayer 1 turn! \nEnter a number (1 to 9).\n");
    scanf("%d",&n);
    if (game[n-1] == ' ')
    {
        game[n-1] = player1;
        turn++;
    }
    else
    {
        printf("\n\t\a ** * Choose an empty space on board * **\n");
        humanTurn();
    }
}

int computerTurn()
{
    printf("\n Computer's turn\n");
    int option = winPossible();
    if(option != 0)
    {
        int option2 = notLetHumanWin();
        if (option2 != 0 && game[4] == ' ')
        {
            game[4] = player2;
        }
        else if (option2 != 0 && game[0] == ' ')
        {
            game[0] = player2;
        }
        else if (option2 != 0 && game[2] == ' ')
        {
            game[2] = player2;
        }
        else if (option2 != 0 && game[6] == ' ')
        {
            game[6] = player2;
        }
        else if (option2 != 0 && game[8] == ' ')
        {
            game[8] = player2;
        }
        else if (option2 != 0 && game[1] == ' ')
        {
            game[1] = player2;
        }
        else if (option2 != 0 && game[3] == ' ')
        {
            game[3] = player2;
        }
        else if (option2 != 0 && game[5] == ' ')
        {
            game[5] = player2;
        }
        else if (option2 != 0 && game[7] == ' ')
        {
            game[7] = player2;
        }
        turn = 0;

    }
}
int player2Turn()
{
    int n;
    printf("\nPlayer 2 turn! \nEnter a number (1 to 9).\n");
    scanf("%d",&n);
    if (game[n-1] == ' ')
    {
        game[n-1] = player2;
        turn = 0;
    }
    else
    {
        printf("\n\t\a ** * Choose an empty space on board * **\n");
        player2Turn();
    }
}
int notLetHumanWin()
{
    if (game[0] == player1 && game[1] == player1 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player1 && game[2] == player1 && game[1] == ' ')
    {
        game[1] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player1 && game[2] == player1 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player1 && game[4] == player1 && game[5] == ' ')
    {
        game[5] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player1 && game[5] == player1 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player1 && game[5] == player1 && game[3] == ' ')
    {
        game[3] = player2;
        turn = 0;
        return turn;
    }
    else if (game[6] == player1 && game[7] == player1 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[6] == player1 && game[8] == player1 && game[7] == ' ')
    {
        game[7] = player2;
        turn = 0;
        return turn;
    }
    else if (game[7] == player1 && game[8] == player1 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player1 && game[3] == player1 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player1 && game[6] == player1 && game[3] == ' ')
    {
        game[3] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player1 && game[6] == player1 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player1 && game[4] == player1 && game[7] == ' ')
    {
        game[7] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player1 && game[7] == player1 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player1 && game[7] == player1 && game[1] == ' ')
    {
        game[1] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player1 && game[5] == player1 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player1 && game[8] == player1 && game[5] == ' ')
    {
        game[5] = player2;
        turn = 0;
        return turn;
    }
    else if (game[5] == player1 && game[8] == player1 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player1 && game[4] == player1 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player1 && game[8] == player1 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player1 && game[8] == player1 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player1 && game[4] == player1 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player1 && game[6] == player1 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player1 && game[6] == player1 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else
        return -1;
}

int winPossible()
{
    if (game[0] == player2 && game[1] == player2 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player2 && game[2] == player2 && game[1] == ' ')
    {
        game[1] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player2 && game[2] == player2 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player2 && game[4] == player2 && game[5] == ' ')
    {
        game[5] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player2 && game[5] == player2 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player2 && game[5] == player2 && game[3] == ' ')
    {
        game[3] = player2;
        turn = 0;
        return turn;
    }
    else if (game[6] == player2 && game[7] == player2 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[6] == player2 && game[8] == player2 && game[7] == ' ')
    {
        game[7] = player2;
        turn = 0;
        return turn;
    }
    else if (game[7] == player2 && game[8] == player2 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player2 && game[3] == player2 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player2 && game[6] == player2 && game[3] == ' ')
    {
        game[3] = player2;
        turn = 0;
        return turn;
    }
    else if (game[3] == player2 && game[6] == player2 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player2 && game[4] == player2 && game[7] == ' ')
    {
        game[7] = player2;
        turn = 0;
        return turn;
    }
    else if (game[1] == player2 && game[7] == player2 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player2 && game[7] == player2 && game[1] == ' ')
    {
        game[1] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player2 && game[5] == player2 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player2 && game[8] == player2 && game[5] == ' ')
    {
        game[5] = player2;
        turn = 0;
        return turn;
    }
    else if (game[5] == player2 && game[8] == player2 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player2 && game[4] == player2 && game[8] == ' ')
    {
        game[8] = player2;
        turn = 0;
        return turn;
    }
    else if (game[0] == player2 && game[8] == player2 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player2 && game[8] == player2 && game[0] == ' ')
    {
        game[0] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player2 && game[4] == player2 && game[6] == ' ')
    {
        game[6] = player2;
        turn = 0;
        return turn;
    }
    else if (game[2] == player2 && game[6] == player2 && game[4] == ' ')
    {
        game[4] = player2;
        turn = 0;
        return turn;
    }
    else if (game[4] == player2 && game[6] == player2 && game[2] == ' ')
    {
        game[2] = player2;
        turn = 0;
        return turn;
    }
    else
        return -1;



}
void displayBoard()
{
    printf("\n\n\t\t");
    printf("%c",game[0]);
    printf("|");
    printf("%c",game[1]);
    printf("|");
    printf("%c",game[2]);
    printf("\n\t\t-----\n\t\t");
    printf("%c",game[3]);
    printf("|");
    printf("%c",game[4]);
    printf("|");
    printf("%c",game[5]);
    printf("\n\t\t-----\n\t\t");
    printf("%c",game[6]);
    printf("|");
    printf("%c",game[7]);
    printf("|");
    printf("%c",game[8]);
    printf(" ");
}

int checkWinner()
{
    if(game[0] == game[1] && game[1] == game[2] && game[0] != ' ')
    {
        return 1;
    }
    else if (game[3] == game[4] && game[4] == game[5] && game[3] != ' ')
    {
        return 1;
    }
    else if (game[6] == game[7] && game[7] == game[8] && game[6] != ' ')
    {
        return 1;
    }
    else if (game[0] == game[3] && game[3] == game[6] && game[0] != ' ')
    {
        return 1;
    }
    else if (game[1] == game[4] && game[4] == game[7] && game[1] != ' ')
    {
        return 1;
    }
    else if (game[2] == game[5] && game[5] == game[8] && game[2] != ' ')
    {
        return 1;
    }
    else if (game[0] == game[4] && game[4] == game[8] && game[0] != ' ')
    {
        return 1;
    }
    else if (game[2] == game[4] && game[4] == game[6] && game[2] != ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int displayMenu()
{

    int choice;
    printf("\n*** * MENU * ***\n");
    printf("Player1 Choose Symbol\n");
    printf("1. Play with 'X' \n");
    printf("2. Play with 'O' \n");
    printf("3. Quit Game\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        player1 = 'X'; player2 = 'O';
        printf("Player 1: %c \nPlayer 2: %c", player1, player2);
    }
    else if (choice == 2)
    {
        player1 = 'O'; player2 = 'X';
        printf("Player 1: %c \nPlayer 2: %c", player1, player2);
    }
    else if (choice == 3)
    {
        printf("Quiting");
        exit(0);
    }
    else
    {
        printf("\a\nInvalid Choice! Enter a digit (1 to 3)\n\n");
        choice = displayMenu();
    }
    return choice;
}

int gameMode()
{
    int n;
    printf("\n Choose game mode: \n");
    printf("1. Human vs Human (2 player)\n");
    printf("2. Human vs Computer (Single player)\n");
    printf("3. Quit\n");
    scanf("%d", &n);
    if (n == 1)
    {
        mode = 0;
        printf("\nHuman VS Human\n");
    }
    else if(n == 2)
    {
        mode = 1;
        printf("\nHuman VS Computer\n");
    }
    else if(n == 3)
    {
        exit(0);
    }
    else
    {
        printf("\a \nInvalid Choice, enter a digit (1 to 3).\n");
        n = gameMode();
    }
    return n;
}
