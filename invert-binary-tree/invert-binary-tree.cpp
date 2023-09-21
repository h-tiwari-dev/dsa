#include <iostream>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *le = root->left;
        root->left = root->right;
        root->right = le;
        return root;
    }
};

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->val;
    printInOrder(root->right);
}

int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(8)));
    printInOrder(root);
    sol->invertTree(root);
    // TreeNode * root = new TreeNode(1, nullptr, new TreeNode(2));
    cout << "Solution is: " << endl;
    printInOrder(root);
}
