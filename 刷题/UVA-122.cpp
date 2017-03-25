#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
/**
 * @class Node
 * @author 79864
 * @date 03/03/2017
 * @file main.cpp
 * @brief 
 * UVa122
 * �������Ĺ�����������BFS��
 */


struct Node{
    
    int value; //����
    Node *left,*right; //�ӽڵ�
    bool has_value; //�洢��ֵ״̬
    Node(): left(NULL),right(NULL),has_value(false){}
};

Node *root; //�������ĸ��ڵ�
Node* newNode() {   return new Node();  } //new���������Ŀռ��ڶ��У������ڷ��������󱻻��� 
/**
 * @brief �����������
 * @param root
 * @param result �����������˳����������
 */
bool bfs(Node *root,vector<int>& result){
    queue<Node*> q;
    q.push(root);
    Node* node;
    while(!q.empty())
    {
        node = q.front(); //ȡ������Ԫ��
        q.pop();
        if(!node->has_value) return false;
        if(node->left!=NULL) q.push(node->left); //���˽ڵ�����������μ������
        if(node->right!=NULL) q.push(node->right);
        result.push_back(node->value);
    }
    return true;
}
int main(){
    

    char nodeMsg[20];
    bool isReadEnd = false;
    while(true)
    {         
        bool error = false; //��־���������������Ƿ��д���
        root = newNode();
        //��ȡһ�����Ľڵ���Ϣ
        while(true)
        {   
            if(! (cin >> nodeMsg) ) 
            {
                isReadEnd = true; //����ȡ����������
                break;
            }
            if(!strcmp(nodeMsg,"()")) break; //�����������Ϣ�Ѿ���ȡ���������
            //�����ַ���
            int value;
            Node *node = root;
            sscanf(nodeMsg+1,"%d",&value); //��ȡ�ýڵ��value
            char *p = strchr(nodeMsg,',');
            //�����ýڵ������е�λ��
            for(int i=1;i<strlen(p);i++)
            {
                if(*(p+i) == 'L')
                {
                    if(node->left == NULL)  node->left = newNode();
                    node = node->left;
                }
                else if(*(p+i) == 'R'){
                    if(node->right == NULL) node->right = newNode();
                    node = node->right;
                }
            }
            if(node->has_value) error = true;
            else{
                node->value = value;
                node->has_value = true;
            }

        }
        vector<int> result;
        if(!isReadEnd){
            if(error)
            {
                cout << "not complete" << endl;
            }
            else if(bfs(root,result))
            {
                for(vector<int>::iterator it = result.begin();it != result.end();it++)
                {
                    cout << *it ;
                    if(it+1!=result.end()) cout << " ";
                    else cout << endl;
                    
                }
            }else cout << "not complete" << endl;
            
        }
        else break;
    }
    
    
    return 0;
}
