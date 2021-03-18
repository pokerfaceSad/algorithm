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
    // 先序遍历寻找与B根结点值相同的A子节点，找到后再次进行先序遍历比对
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == NULL) return false;
        if (A == NULL) return false;
        if (A->val == B->val && isTreeEqual(A, B)) return true;
        return isSubStructure(A->right, B) || isSubStructure(A->left, B);
    }

    bool isTreeEqual(TreeNode* A, TreeNode* B) {
        if (B == NULL) return true;
        if (A == NULL) return false;
        if (A->val != B->val) return false;
        return isTreeEqual(A->right, B->right) && isTreeEqual(A->left, B->left);
    }
};