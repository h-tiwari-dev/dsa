#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> rows_first_elements;
        for (auto row : matrix)
        {
            rows_first_elements.push_back(row[0]);
        }

        int index = 0;
        for (int i = 0; i < rows_first_elements.size(); i++)
        {
            if (rows_first_elements[i] < target)
            {
                index = i;
            }
            else
            {
                break;
            }
        }
        return binary_search(matrix[index].begin(), matrix[index].end(), target);
    }
};

int main()
{
    auto sol = new Solution();
    // vector<vector<int>> test = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // vector<vector<int>> test = {{1}, {3}};
    // cout << sol->searchMatrix(test, 3);

    cout << 4 / 3;
    // sol->partition(test, 0, test.size(), 3);
    // cout << sol->findKthLargest(test, 4) << endl;

    // vector<vector<int>> test = {
    //     {1, 4},
    //     {2, 3},
    // };

    // auto result = sol->merge(test);
    // for (auto res : result)
    // {
    //     cout << "[ ";
    // for (auto r : test)
    // {
    //     cout << r << ", ";
    // }
    // //     cout << "]";
    // //     cout << endl;
    // // }
    return 0;
}