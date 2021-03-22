# include <iostream>
# include <queue>
# include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // bool isBalanced(TreeNode* root) {
    //     if (root == NULL) return true;
    //     if (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1)
    //         return isBalanced(root->left) && isBalanced(root->right);
    //     else return false;
    // }

    // int maxDepth(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    // }
    
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        if (leftDepth == -1) return -1;
        int rightDepth = maxDepth(root->right);
        if (rightDepth == -1) return -1;
        if (abs(leftDepth - rightDepth) > 1) return -1;
        else return max(leftDepth, rightDepth) + 1;
    }

};