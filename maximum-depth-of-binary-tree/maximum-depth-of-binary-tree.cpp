#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            int level = 0;
            dfs(root, level);
            return level;
        }

        int dfs(TreeNode * root, int &level){
            if(root == nullptr){
                return 0;
            }
            int maxLeft = dfs(root->left, level);
            int maxRight = dfs(root->right, level);
            level = 1 + max(maxLeft, maxRight);

            return level;
        }
};

int main(){
    Solution * sol = new Solution();
    // TreeNode * root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode * root = new TreeNode(1, nullptr, new TreeNode(2));

    cout << "Solution is: " << sol->maxDepth(root);
}
