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
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        dfs(res, root);
        return res[k-1];
    }

    void dfs(vector<int>& res, TreeNode* root) {
        if (root == NULL) return;
        dfs(res, root->right);
        res.push_back(root->val);
        dfs(res, root->left);
    }
};