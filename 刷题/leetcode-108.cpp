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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int> nums, int start, int end) {
        TreeNode* root = new TreeNode(nums[(start + end) / 2]);
        if (start == end) return root;
        if (start > end) return NULL;
        root->left = helper(nums, start, (start + end) / 2 - 1);
        root->right = helper(nums, (start + end) / 2 + 1, end);
        return root;
    }
};

int main() {
    vector<int> v;
    v.push_back(-10);
    v.push_back(-3);
    v.push_back(0);
    v.push_back(5);
    v.push_back(9);
    Solution s;
    s.sortedArrayToBST(v);
}