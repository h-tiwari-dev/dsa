#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int solveNQueens(int n)
    {
        vector<vector<string>> board;
        vector<pair<int, int>> queens;

        for (int i = 0; i < n; i++)
        {
            vector<string> new_vec;
            for (int j = 0; j < n; j++)
            {
                new_vec.push_back(".");
            }
            board.push_back(new_vec);
        }
        int solutions = 0;

        solve(board, queens, n, 0, solutions);

        return solutions;
    }

    bool isSave(const pair<int, int> &pos, const vector<pair<int, int>> &queens)
    {
        for (auto queen : queens)
        {
            if (queen.first == pos.first || queen.second == pos.second)
            {
                return false;
            }
            if ((queen.first - 1 == pos.first && queen.second - 1 == pos.second) || (queen.first - 1 == pos.first && queen.second + 1 == pos.second) ||
                (queen.first + 1 == pos.first && queen.second - 1 == pos.second) ||
                (queen.first + 1 == pos.first && queen.second + 1 == pos.second))
            {
                return false;
            }
            if (abs(queen.first - pos.first) == abs(queen.second - pos.second))
            {
                return false;
            }
        }
        return true;
    }

    int solve(vector<vector<string>> &board, vector<pair<int, int>> &queens, int n, int row, int &solutions)
    {
        for (int i = 0; i < n; i++)
        {
            if (row < n && board[row][i] == "." && isSave({row, i}, queens))
            {
                board[row][i] = "Q";
                queens.push_back({row, i});
                if (solve(board, queens, n, row + 1, solutions))
                {
                    solutions += 1;
                }
                board[row][i] = ".";
                queens.pop_back();
            }
        }
        if (queens.size() == n)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->solveNQueens(4);
    cout << result << "\n";
    // for (auto res : result)
    // {
    //     for (auto r : res)
    //     {
    //         cout << r << " ,";
    //     }
    //     cout << "\n";
    // }
    return 0;
}