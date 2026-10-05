#include <iostream>
using namespace std;

const int N = 4;

int board[N][N] = {0};

bool isSafe(int row, int col)
{
    // Check same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N;
         i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int row)
{
    // Base case
    if (row == N)
        return true;

    // Try every column in the current row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recursively place queen in next row
            if (solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

void displayBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}

int main()
{
    if (solveNQueens(0))
        displayBoard();
    else
        cout << "No solution exists.";

    return 0;
}