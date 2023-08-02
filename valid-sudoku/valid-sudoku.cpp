#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    pair<int, int> getBoxLocation(int i, int j)
    {
        return {i / 3, j / 3};
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        auto row_wise_dp = map<int, set<char>>();
        auto col_wise_dp = map<int, set<char>>();
        auto box_wise_dp = map<pair<int, int>, set<char>>();

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                auto box_location = getBoxLocation(i, j);
                if (row_wise_dp.find(i) == row_wise_dp.end())
                {
                    row_wise_dp[i] = {};
                }
                if (col_wise_dp.find(i) == col_wise_dp.end())
                {
                    col_wise_dp[i] = {};
                }
                if (box_wise_dp.find(box_location) == box_wise_dp.end())
                {
                    box_wise_dp[{i, j}] = {};
                }

                if (board[i][j] == '.')
                {
                    continue;
                }
                if (row_wise_dp[i].find(board[i][j]) == row_wise_dp[i].end())
                {
                    row_wise_dp[i].insert(board[i][j]);
                }
                else
                {
                    return false;
                }
                if (col_wise_dp[j].find(board[i][j]) == col_wise_dp[j].end())
                {
                    col_wise_dp[j].insert(board[i][j]);
                }
                else
                {
                    return false;
                }
                if (box_wise_dp[box_location].find(board[i][j]) == box_wise_dp[box_location].end())
                {
                    box_wise_dp[box_location].insert(board[i][j]);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    auto sol = Solution();
    vector<vector<char>> test = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    auto result = sol.isValidSudoku(test);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << endl;

    return 0;
}