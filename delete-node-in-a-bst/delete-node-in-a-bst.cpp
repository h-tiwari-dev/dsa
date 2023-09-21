#include <iostream>

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
    TreeNode *_opp;
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root != nullptr)
        {
            if (root->val < key)
            {
                root->right = deleteNode(root->right, key);
            }
            else if (root->val > key)
            {
                root->left = deleteNode(root->left, key);
            }
            else
            {
                if (root->left == nullptr && root->right == nullptr)
                {
                    return nullptr;
                }
                if (root->left == nullptr || root->right == nullptr)
                {
                    return root->left == nullptr ? root->right : root->left;
                }

                TreeNode *temp = root->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};

void printInorder(TreeNode *root)
{
    if (root == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    printInorder(root->left);

    std::cout << root->val << ", ";

    printInorder(root->right);
}

int main()
{
    Solution *sol = new Solution();
    TreeNode *tree = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7)));

    printInorder(tree);

    sol->deleteNode(tree, 3);

    printInorder(tree);
    return 0;
}
