# include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 中序遍历
    Node* treeToDoublyList(Node* root) {
        return dfs(root);
    }

    Node* dfs(Node* root) {
        if (!root) return NULL;
        Node* leftHead = dfs(root->left);
        Node* rightHead = dfs(root->right);

        if (leftHead != NULL && rightHead != NULL) {
            // 左子树连接root
            leftHead->left->right = root;
            root->left = leftHead->left;
            // 左右子树首尾相连
            leftHead->left = rightHead->left;
            rightHead->left->right = leftHead;
            // 右子树连接root
            root->right = rightHead;
            rightHead->left = root;

            return leftHead;
        } else if (leftHead == NULL && rightHead != NULL) {
            // 左子树为空
            root->left = rightHead->left;
            rightHead->left->right = root;
            root->right = rightHead;
            rightHead->left = root;

            return root;
        } else if (rightHead == NULL && leftHead != NULL) {
            // 右子树为空
            leftHead->left->right = root;
            root->left = leftHead->left;
            leftHead->left = root;
            root->right = leftHead;            
            return leftHead;
        } else if (rightHead == NULL && leftHead == NULL) {
            root->left = root;
            root->right = root;
            return root;
        }
        return NULL;
    }
};