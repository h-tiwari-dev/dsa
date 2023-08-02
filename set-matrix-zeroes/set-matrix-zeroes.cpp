#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> row_zeros;
        set<int> col_zeros;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_zeros.insert(i);
                    col_zeros.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if ((row_zeros.find(i) != row_zeros.end()) || (col_zeros.find(j) != col_zeros.end()))
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
int main()
{
    auto sol = Solution();
    vector<vector<int>> test = {{0, 1, 1, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    sol.setZeroes(test);
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