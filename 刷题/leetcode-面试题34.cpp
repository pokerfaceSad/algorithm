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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        helper(root, target, 0);
        return res;
    }

    void helper(TreeNode* root, int target, int pathSum) {
        if (root == NULL) return;
        pathSum += root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (target == pathSum) {
                res.push_back(path);
                return;
            }
            else return;
        } else {
            if (root->left != NULL) {
                helper(root->left, target, pathSum);
                path.pop_back();
            }
            if (root->right != NULL) {
                helper(root->right, target, pathSum);
                path.pop_back();
            }
        }
    }
};