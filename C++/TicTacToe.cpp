#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class TicTacToe
{
private:
    char matrix[3][3];                 // Game board
    string player1, player2;
    int count;

public:
    TicTacToe();                       // Constructor to initialize game
    void displayBoard();               // Function to display the board
    char checkWin();                   // Function to check the winning condition
    void getPlayerNames();             // Function to get player names
    void playerMove(int player);       // Function for player move
    void playGame();                   // Main function to play the game
    void displayMenu();                // Function to display the game menu
    void howToPlay();                  // Function to display instructions
};

TicTacToe::TicTacToe()
{
    count = 0;
    
    char num = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = num++;
        }
    }
}

void TicTacToe::displayBoard()
{
    cout << "||---||---||---||" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "||";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << matrix[i][j] << " ||";
        }
        cout << endl << "||---||---||---||" << endl;
    }
}

char TicTacToe::checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return matrix[i][0];
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return matrix[0][i];
    }
  
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];

    return '$'; // Return '$' if no one has won
}

void TicTacToe::getPlayerNames()
{
    cout << "\nEnter player's name who is choosing 'X': ";
    getline(cin, player1);
    cout << "\nWelcome " << player1 << "! Your icon is 'X'.";

    cout << "\nEnter player's name who is choosing 'O': ";
    getline(cin, player2);
    cout << "\nWelcome " << player2 << "! Your icon is 'O'.";
}


void TicTacToe::playerMove(int player)
{
    char move;
    bool validMove = false;

    while (!validMove)
    {
        cout << "\n\n\nTurn for " << (player == 1 ? player1 : player2) << " ('" << (player == 1 ? 'X' : 'O') << "')...\n";
        cin >> move;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == move) 
                {
                    matrix[i][j] = (player == 1 ? 'X' : 'O');
                    validMove = true;
                    count++;
                }
            }
        }

        if (!validMove)
        {
            cout << "Invalid move, try again.\n";
        }
    }

    system("cls");
    displayBoard();
}

void TicTacToe::playGame()
{
    char result;
    int turn = 1;

    while (count < 9)
    {
        playerMove(turn); 
        result = checkWin();

        if (result == 'X')
        {
            cout << "\n\nCongratulations " << player1 << "! You have won the game!!!!";
            return;
        }
        else if (result == 'O')
        {
            cout << "\n\nCongratulations " << player2 << "! You have won the game!!!!";
            return;
        }

        turn = (turn == 1 ? 2 : 1);
    }

    cout << "\n\nIt's a tie!!!!!";
}

void TicTacToe::displayMenu()
{
    int choice;

    while (true)
    {
        system("cls");
        cout << "\n1. Start the game.";
        cout << "\n2. How to play?";
        cout << "\n3. Quit the game.";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            system("cls");
            getPlayerNames();
            system("pause");
            system("cls");
            displayBoard();
            playGame();
            cout << "\n\n\n\t\t\t\tGAME OVER\n";
            system("pause");
            break;

        case 2:
            howToPlay();
            break;

        case 3:
            exit(0); // Exit the game
            break;

        default:
            cout << "\nInvalid choice, please try again.";
            break;
        }
    }
}

void TicTacToe::howToPlay()
{
    system("cls");
    cout << "\n\n\t\t\t\t:_INSTRUCTIONS:_\n";
    cout << "\n\tThe game is played on a grid that's 3 squares by 3 squares.\n";
    cout << "\tYou are X, your friend is O. Players take turns putting their marks in empty squares.\n";
    cout << "\tThe first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n";
    cout << "\tWhen all 9 squares are full, the game is over.\n\n\t\t\t";
    system("pause");
}

int main()
{
    system("Color 3F"); 
    TicTacToe game;
    game.displayMenu();
    return 0;
}
