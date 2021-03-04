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
# include <iostream>
# include <vector>
# include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> current_level;
        TreeNode* cur;
        q.push(root);
        int level_node_num;
        while (!q.empty()) {
            level_node_num = q.size();
            current_level.clear();
            while(level_node_num > 0) {
                cur = q.front(); q.pop(); level_node_num--;
                current_level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(current_level);
        }
        return res;
    }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if (!root) return {};
    //     queue<TreeNode*> q1, q2;
    //     vector<vector<int>> res;
    //     bool isQ1 = true;
    //     TreeNode* cur;
    //     q1.push(root);
    //     vector<int> current_level;
    //     while (!q1.empty() || !q2.empty()) {
    //         if (isQ1) {
    //             cur = q1.front(); q1.pop();
    //             current_level.push_back(cur->val);
    //             if (cur->left != NULL) q2.push(cur->left);
    //             if (cur->right != NULL) q2.push(cur->right);
    //             if (q1.empty()) {
    //                 res.push_back(current_level);
    //                 isQ1 = !isQ1;
    //                 current_level.clear();
    //             }
    //         } else {
    //             cur = q2.front(); q2.pop();
    //             current_level.push_back(cur->val);
    //             if (cur->left != NULL) q1.push(cur->left);
    //             if (cur->right != NULL) q1.push(cur->right);
    //             if (q2.empty()) {
    //                 res.push_back(current_level);
    //                 isQ1 = !isQ1;
    //                 current_level.clear();
    //             }
    //         }

    //     }
    //     return res;
    // }
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
    vector<vector<int>> res = s.levelOrder(node1);
    for (auto v : res) {
        for (auto i : v)
            cout << i << endl;
        cout << "---" << endl;
    }
    return 0;
}