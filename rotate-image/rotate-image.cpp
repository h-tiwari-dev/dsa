#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int matrix_size = matrix.size();
        int row_size = sizeof(matrix[0]) / sizeof(matrix[0][0]);

        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix_size; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    auto sol = Solution();
    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(test);
    cout << "Result:- \n";
    for (auto i : test)
    {
        for (auto j : i)
        {
            cout << j;
            cout << ",";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}