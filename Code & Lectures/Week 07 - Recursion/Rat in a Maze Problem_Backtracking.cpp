#include <iostream>
using namespace std;

const int N = 4;

int maze[N][N] =
{
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {0, 1, 1, 1}
};

int solution[N][N] = {0};

bool isSafe(int row, int col)
{
    if (row >= 0 && row < N &&
        col >= 0 && col < N &&
        maze[row][col] == 1)
    {
        return true;
    }

    return false;
}

bool solveMaze(int row, int col)
{
    // Base case
    if (row == N - 1 && col == N - 1)
    {
        solution[row][col] = 1;
        return true;
    }

    if (isSafe(row, col))
    {
        // Mark current cell
        solution[row][col] = 1;

        // Move Down
        if (solveMaze(row + 1, col))
            return true;

        // Move Right
        if (solveMaze(row, col + 1))
            return true;

        // Backtrack
        solution[row][col] = 0;
    }

    return false;
}

void displaySolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solution[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    if (solveMaze(0, 0))
        displaySolution();
    else
        cout << "No path exists.";

    return 0;
}