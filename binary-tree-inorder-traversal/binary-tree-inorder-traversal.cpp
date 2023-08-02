#include <bits/stdc++.h>
#include <bitset>

using namespace std;

//   Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        this->_inorderTraversal(root, result);
        return result;
    }

    void _inorderTraversal(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
        {
            return;
        }
        _inorderTraversal(root->left, result);
        result.push_back(root->val);
        _inorderTraversal(root->right, result);
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    auto sol = Solution();
    auto inorder_result = sol.inorderTraversal(tree);

    for (auto in_res : inorder_result)
    {
        cout << in_res << " ,";
    }

    return 0;
}