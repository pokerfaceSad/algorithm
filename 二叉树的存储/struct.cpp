/*
	Date: 16/03/17 11:47
	Description: �ýṹ�弰ָ��洢��ϵ�ķ�ʽ����������
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int value;
    Node *left,*right;
    Node():left(NULL),right(NULL){}
};

void bfs(Node *root,vector<int>& output);
void dfs(Node *node,vector<int>& output);
Node* root;
int main(){
    
    root = new Node();
    root->value = 0;
    
    Node *node;
    
    node = new Node();
    node->value = 1;
    root->left = node;
    
    node = new Node();
    node->value = 2;
    root->right = node;
    
    node = new Node();
    node->value = 3;
    root->left->left = node;
    
    node = new Node();
    node->value = 4;
    root->left->right = node;
    
    node = new Node();
    node->value = 5;
    root->right->left = node;
    
    node = new Node();
    node->value = 6;
    root->right->right = node;
    
    vector<int> output;
//    bfs(root,output);
    dfs(root,output);
	
    
    for(vector<int>::iterator it = output.begin();it != output.end();it++)
        cout << *it <<" ";
}
/**
 * @brief ����������������ϵ��£��������ң�
 * @param root
 * @param output
 */
void bfs(Node* root,vector<int>& output){
    queue<Node*> q;
    q.push(root);
    output.clear();
    Node *node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        output.push_back(node->value);
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
    
}

/*
	dfs���������������������� 
*/



void dfs(Node *node,vector<int>& output){
	
	if(node->left != NULL) dfs(node->left,output);
	if(node->right != NULL) dfs(node->right,output);
	output.push_back(node->value); 
}
