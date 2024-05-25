#include <iostream>
#include <vector>

using namespace std;

// Function to print the board
void printSolution(const vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int i, j;
    int N = board.size();

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens problem
bool solveNQueensUtil(vector<vector<int>> &board, int col)
{
    int N = board.size();

    // If all queens are placed then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution then remove it
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column col, then return false
    return false;
}

// This function solves the N-Queens problem using Backtracking. It mainly uses solveNQueensUtil() to solve the problem. It returns false if queens cannot be placed, otherwise, it returns true and prints the placement of queens in the form of 1s. Note that there may be more than one solution, this function prints one of the feasible solutions.
bool solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    int N = 8; // You can change the value of N to solve for different sizes
    solveNQueens(N);
    return 0;
}
