/*

Snake, water, gun, or rock, paper, scissors is a game most of us have played during our school time (I sometimes play it even now)

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int player, computer = rand() % 3;
    /*
        0 --> Snake
        1 --> Water
        2 --> Gun
    */
    cout << "Choose 0 for Snake, 1 for Water, and 2 for Gun" << endl;
    cin >> player;
    cout << "Computer chose " << computer << endl;

    if (player == 0 && computer == 0)
    {
        cout << "It's a Draw!" << endl;
    }
    else if (player == 0 && computer == 1)
    {
        cout << "You Win!" << endl;
    }
    else if (player == 0 && computer == 2)
    {
        cout << "You Lose!" << endl;
    }
    else if (player == 1 && computer == 0)
    {
        cout << "You Lose!" << endl;
    }
    else if (player == 1 && computer == 1)
    {
        cout << "It's a Draw!" << endl;
    }
    else if (player == 1 && computer == 2)
    {
        cout << "You Win!" << endl;
    }
    else if (player == 2 && computer == 0)
    {
        cout << "You Win!" << endl;
    }
    else if (player == 2 && computer == 1)
    {
        cout << "You Lose!" << endl;
    }
    else if (player == 2 && computer == 2)
    {
        cout << "It's a Draw!" << endl;
    }
    else
    {
        cout << "Something went wrong!" << endl;
    }

    return 0;
}