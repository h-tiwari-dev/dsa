#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        map<int, vector<int>> data_map;
        vector<vector<int>> result;

        if (root != nullptr)
        {
            doStuff(root, 0, data_map);
        }
        for (auto val : data_map)
        {
            result.push_back(val.second);
        }
        return result;
    }

    void doStuff(TreeNode *root, int level, map<int, vector<int>> &data_map)
    {
        data_map[level].push_back(root->val);
        if (root->left != nullptr)
        {
            doStuff(root->left, level + 1, data_map);
        }
        if (root->right != nullptr)
        {
            doStuff(root->right, level + 1, data_map);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    Solution *sol = new Solution();
    auto result = sol->levelOrder(root);
    for (auto val : result)
    {
        for (auto v : val)
        {
            cout << v << ", ";
        }
        cout << endl;
    }
    return 0;
}
