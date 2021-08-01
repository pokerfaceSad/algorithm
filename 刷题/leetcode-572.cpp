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
# include <sstream>
# include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ostringstream oss;
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        oss.str(""); oss << " ";
        getDFSString(root);
        string root_str = oss.str(); oss.str(""); oss << " ";
        getDFSString(subRoot);
        string sub_str = oss.str(); oss.str(""); oss << " ";
        if (root_str.find(sub_str) == string::npos) return false;
        else return true;
        
    }

    void getDFSString(TreeNode* root) {
        if (root == NULL) {
            oss << "rootNull ";
            return;
        } else oss << to_string(root->val) << " ";
        if (root->left == NULL) oss << "lnull ";
        else getDFSString(root->left);
        if (root->right == NULL) oss << "rnull ";
        else getDFSString(root->right);
    }
};

int main() {
    TreeNode n0(12);
    // TreeNode n1(2);
    // TreeNode n2(3);
    // TreeNode n3(4);
    // TreeNode n4(5);
    // n0.left = &n1;
    // n0.right = &n2;
    // n1.left = &n3;
    // n1.right = &n4;
    Solution s;
    oss.str(""); oss << "*";
    s.getDFSString(&n0);
    cout << oss.str() << endl;

    return 0;
}