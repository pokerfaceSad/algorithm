# include <iostream>
# include <climits>
# include <stack>
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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long lower, long upper) {
        if (root == NULL) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) && \
               helper(root->right, root->val, upper);
    }

    // 二叉搜索树的中序遍历序列一定是一个升序序列
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur_node = root;
        long pre_val = LONG_MIN;
        if (root == NULL) return;
        while (cur_node != NULL || !stk.empty()) {
            if (cur_node != NULL) {
                stk.push(cur_node);
                cur_node = cur_node->left;
            } else {
                cur_node = stk.top();
                stk.pop();

                // 依次判断中序遍历的结果是否是一个升序序列
                if (cur_node->val <= pre_val) return false;
                pre_val = cur_node->val;
                
                cur_node = cur_node->right;
            }
        }
    }
};

int main() {
    return 0;
}