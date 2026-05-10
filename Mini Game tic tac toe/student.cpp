#include <iostream>

using namespace std;

char board[3][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";
    cout << "     TIC TAC TOE GAME\n";
    cout << "-------------------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "     ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "    -----------\n";
    }

    cout << endl;
}

bool checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
        {
            return true;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
        {
            return true;
        }
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
    {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void playerMove()
{
    int choice;
    int row, col;

    cout << "Player " << currentPlayer << ", Enter Position (1-9): ";
    cin >> choice;

    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
    {
        cout << "Invalid Position! Try Again.\n";
        playerMove();
    }
    else if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "Position Already Filled! Try Again.\n";
        playerMove();
    }
    else
    {
        board[row][col] = currentPlayer;
    }
}

void switchPlayer()
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

void resetBoard()
{
    char value = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value;
            value++;
        }
    }

    currentPlayer = 'X';
}

int main()
{
    char replay;

    do
    {
        resetBoard();

        while (true)
        {
            displayBoard();

            playerMove();

            displayBoard();

            if (checkWin())
            {
                cout << "Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw())
            {
                cout << "Game Draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "\nDo You Want to Play Again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThank You for Playing Tic Tac Toe!\n";

    return 0;
}
