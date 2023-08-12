#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, int value, vector<vector<char>> &board)
    {
        char val = static_cast<char>(value + '0');
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
            if (board[i][col] == val)
            {
                return false;
            }
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
            {
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    int solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(i, j, k, board))
                        {
                            board[i][j] = static_cast<char>(k + '0');
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    auto sol = new Solution();
    // vector<vector<int>> test = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::vector<std::vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '5', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    sol->solveSudoku(board);

    for (auto vec : board)
    {
        for (auto val : vec)
        {
            cout << val << " ,";
        }
        cout << "\n";
    }
    return 0;
}