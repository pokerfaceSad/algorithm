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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) {
            // q == root || q == root既是初始判断也是剪枝
            // 当在遍历中找到p、q其中一个时后面已经不用再继续寻找
            // 只需判断另一个方向的搜索是否成功即可知道LCA节点的位置
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (l && r) return root;
        else if (r == NULL) return l;
        else if (l == NULL) return r;
        else return NULL;

    }
};