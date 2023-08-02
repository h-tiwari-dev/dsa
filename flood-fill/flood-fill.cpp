#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> data_queue;
        set<pair<int, int>> visitedArr;
        int x(sr), y(sc);
        data_queue.push({x, y});
        visitedArr.insert({x, y});
        int size_x(image.size()), size_y(image[0].size());
        int initialColor = image[x][y];

        while (!data_queue.empty())
        {
            pair<int, int> current_node = data_queue.front();
            data_queue.pop();
            if (initialColor == image[current_node.first][current_node.second])
            {

                image[current_node.first][current_node.second] = color;
            }

            for (auto neighbor : this->getNeighbors(current_node.first, current_node.second, size_x, size_y))
            {
                if (visitedArr.find(neighbor) == visitedArr.end() && image[neighbor.first][neighbor.second] == initialColor)
                {
                    visitedArr.insert(neighbor);
                    data_queue.push(neighbor);
                }
            }
        }
        return image;
    }

    vector<pair<int, int>> getNeighbors(int x, int y, int size_x, int size_y)
    {
        vector<pair<int, int>> neighbors;

        if (x + 1 < size_x)
        {
            neighbors.push_back({x + 1, y});
        }
        if (x - 1 >= 0)
        {
            neighbors.push_back({x - 1, y});
        }

        if (y + 1 < size_y)
        {
            neighbors.push_back({x, y + 1});
        }
        if (y - 1 >= 0)
        {
            neighbors.push_back({x, y - 1});
        }
        return neighbors;
    }
};

int main()
{
    vector<vector<int>> test = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    auto sr = 1, sc = 1, color = 2;
    vector<vector<int>> acc_result = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    auto sol = new Solution();
    auto cal_result = sol->floodFill(test, sr, sc, color);

    assert(cal_result.size() == acc_result.size());
    for (int i = 0; i < cal_result.size(); i++)
    {
        assert(cal_result[i].size() == acc_result[i].size());
        for (int j = 0; j < cal_result[i].size(); j++)
        {
            assert(cal_result[i][j] == acc_result[i][j]);
        }
    }
    return 0;
}
