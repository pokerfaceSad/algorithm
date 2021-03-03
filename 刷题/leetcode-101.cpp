# include <iostream>
# include <vector>
# include <queue>
# include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    // 递归
    /*
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
    bool check(TreeNode* leftSubTree, TreeNode* rightSubTree) {
        if (leftSubTree == NULL && rightSubTree == NULL) return true;
        if (leftSubTree == NULL || rightSubTree == NULL) return false;
        if (leftSubTree->val == rightSubTree->val) 
            return check(leftSubTree->left, rightSubTree->right) && check(leftSubTree->right, rightSubTree->left);
        return false;
    }
    */
    // 迭代
    bool isSymmetric(TreeNode* root) {
        // 借助队列同时对两个子树进行广度优先搜索BFS
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *leftSub, *rightSub;
        while(!q.empty()) {
            leftSub = q.front(); q.pop();
            rightSub = q.front(); q.pop();

            if (!leftSub && !rightSub) continue;
            if (!leftSub || !rightSub) return false;
            if (leftSub->val == rightSub->val) {
                q.push(leftSub->left);
                q.push(rightSub->right);

                q.push(leftSub->right);
                q.push(rightSub->left);
            } else return false;
        }
        return true;
    }

    // BFS
    void bfs(TreeNode* root, vector<int>& seq) {
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        while (!q.empty()) {
            cur = q.front(); q.pop();
            seq.push_back(cur->val);
            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
        }
    }
};

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(2);
    node1->left = node2;
    node2->left = node3;
    node1->right = node4;
    node4->left = node5;
    Solution s;
    vector<int> res;
    s.bfs(node1, res);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}