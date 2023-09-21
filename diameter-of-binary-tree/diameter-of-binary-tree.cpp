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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);

        return ans;
    }

    int dfs(TreeNode * root, int &ans){
        if(root == nullptr){
            return 0;
        }

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
int main()
{
    // TreeNode * root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    // TreeNode * root = new TreeNode(1, nullptr, new TreeNode(2));
    TreeNode *root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr);
    Solution *sol = new Solution();

    cout << "Solution is: " << sol->diameterOfBinaryTree(root);
    return 0;
}
