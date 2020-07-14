/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
# include <stdio.h>
# include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    int leftDepth = 0, rightDepth = 0;
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left != NULL) leftDepth = maxDepth(root->left);
    if(root->right != NULL) rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}

int main(){
    struct TreeNode* n1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* n2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* n3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));


    n1->val = 1;
    n1->left = n2;
    n1->right = NULL;
    n2->val = 2;
    n2->left = n3;
    n2->right = NULL;
    n3->val = 3;
    n3->left = NULL;
    n3->right = NULL;
    
    printf("%d", maxDepth(n1));
}
