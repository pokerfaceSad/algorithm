# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        vector<vector<int>> res;
        int level_len = 0;
        bool flag = true;
        while (!q.empty()) {
            level_len = q.size();
            vector<int> level(level_len, 0);
            for (int i = 0 ; i < level_len ; i++) {
                cur = q.front(); q.pop();
                if (flag)
                    level[i] = cur->val;
                else level[level_len - i - 1] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                
            }
            res.push_back(level);
            flag = !flag;    
        }
        return res;
    }
};