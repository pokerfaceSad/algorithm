# include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode* tmp_left = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp_left);
        return root;
        
    }
};