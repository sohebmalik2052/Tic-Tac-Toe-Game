#include <iostream>
#include <limits>
using namespace std;

char board[3][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the game board
void displayBoard()
{
    cout << "\n";
    cout << "=====================\n";
    cout << "      TIC-TAC-TOE\n";
    cout << "=====================\n";

    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  "
         << board[0][1] << "  |  "
         << board[0][2] << "\n";

    cout << "-----|-----|-----\n";

    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  "
         << board[1][1] << "  |  "
         << board[1][2] << "\n";

    cout << "-----|-----|-----\n";

    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  "
         << board[2][1] << "  |  "
         << board[2][2] << "\n";

    cout << "     |     |     \n";
    cout << "\n";
}

// Reset the board
void resetBoard()
{
    char value = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }
}

// Check whether a player has won
bool checkWinner(char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check whether the board is full
bool boardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// Make a player's move
bool makeMove(int position, char player)
{
    if (position < 1 || position > 9)
    {
        return false;
    }

    int row = (position - 1) / 3;
    int column = (position - 1) % 3;

    if (board[row][column] == 'X' ||
        board[row][column] == 'O')
    {
        return false;
    }

    board[row][column] = player;

    return true;
}

// Play one complete game
void playGame()
{
    resetBoard();

    char currentPlayer = 'X';
    int position;

    while (true)
    {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";

        cin >> position;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input! Enter a number from 1 to 9.\n";
            continue;
        }

        if (!makeMove(position, currentPlayer))
        {
            cout << "\nInvalid move! Choose an empty position.\n";
            continue;
        }

        if (checkWinner(currentPlayer))
        {
            displayBoard();

            cout << "********************************\n";
            cout << "   Player " << currentPlayer << " WINS!\n";
            cout << "********************************\n";

            break;
        }

        if (boardFull())
        {
            displayBoard();

            cout << "********************************\n";
            cout << "       GAME DRAW!\n";
            cout << "********************************\n";

            break;
        }

        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }
}

int main()
{
    char again;

    cout << "\n====================================\n";
    cout << "       WELCOME TO TIC-TAC-TOE\n";
    cout << "====================================\n";

    do
    {
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "\nThank you for playing Tic-Tac-Toe!\n";
    cout << "Goodbye!\n";

    return 0;
}
