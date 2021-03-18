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
        queue<TreeNode*> q, tmp;
        q.push(root);
        TreeNode* cur;
        vector<vector<int>> res;
        vector<int> level;
        res.push_back(level);
        while (!q.empty()) {
            cur = q.front(); q.pop();
            if(cur) {
                res[res.size()-1].push_back(cur->val);
                if (cur->left) tmp.push(cur->left);
                if (cur->right) tmp.push(cur->right);
            }
            if (q.empty() && !tmp.empty()) {
                vector<int> level;
                res.push_back(level);
                while(!tmp.empty()) {
                    q.push(tmp.front()); tmp.pop();
                }
            }
        }
        return res;
    }
};