/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> hashtable;
public:
    TreeNode* getRoot(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight) return NULL;
        TreeNode* root = new TreeNode(preorder[preLeft]);
        if (preLeft == preRight) return root;
        // 找到根节点的值在中序遍历序列中的位置
        int rootInPos = hashtable[preorder[preLeft]];
        int leftLen = rootInPos - inLeft;
        root->left = getRoot(preorder, preLeft+1, preLeft+1+leftLen-1, inorder, inLeft, rootInPos-1);
        root->right = getRoot(preorder, preLeft+2+leftLen-1, preRight, inorder, rootInPos+1, inRight);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return {};
        hashInOrder(inorder);
        return getRoot(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    void hashInOrder(vector<int>& inorder) {
        int len = inorder.size();
        for (int i = 0 ; i < len ; i++) {
            hashtable[inorder[i]] = i;
        }
    }
};

int main() {
    return 0;
}