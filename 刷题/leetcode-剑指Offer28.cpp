# include <iostream>
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
    // 借助队列同时对左右两颗子树进行bfs
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode* leftSub,* rightSub;
        while (!q.empty()) {
            leftSub = q.front(); q.pop();
            rightSub = q.front(); q.pop();

            if (!leftSub && !rightSub) continue; // 都是NULL
            if (!leftSub || !rightSub) return false; // 只有一个NULL
            if (leftSub->val != rightSub->val) return false;
            else {
                q.push(leftSub->left);
                q.push(rightSub->right);
                q.push(leftSub->right);
                q.push(rightSub->left);
            }
        }
        return true;
    }
};