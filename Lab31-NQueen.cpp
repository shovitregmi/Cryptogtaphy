#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 15

void printSolution(vector<vector<int>> &board, int N)
{
    cout << "Solution:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] == 1 ? " Q " : " . ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void solveNQueens(vector<vector<int>> &board, int col, int N, int &solutionCount)
{
    if (col >= N)
    {
        printSolution(board, N);
        solutionCount++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            solveNQueens(board, col + 1, N, solutionCount);
            board[i][col] = 0;
        }
    }
}

int main()
{

    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    if (N <= 0 || N > MAX_N)
    {
        cout << "The number of queens must be between 1 and " << MAX_N << ".\n";
        return 1;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));
    int solutionCount = 0;

    solveNQueens(board, 0, N, solutionCount);

    if (solutionCount == 0)
    {
        cout << "No solution exists for N = " << N << ".\n";
    }
    else
    {
        cout << "Total number of solutions: " << solutionCount << "\n";
    }

    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";
    return 0;
}