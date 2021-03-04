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
 * 二叉树的构建及遍历（BFS）
 */


struct Node{
    
    int value; //数据
    Node *left,*right; //子节点
    bool has_value; //存储赋值状态
    Node(): left(NULL),right(NULL),has_value(false){}
};

Node *root; //二叉树的根节点
Node* newNode() {   return new Node();  } //new运算符申请的空间在堆中，不会在方法结束后被回收 
/**
 * @brief 宽度优先搜索
 * @param root
 * @param result 将搜索结果按顺序存入该数组
 */
bool bfs(Node *root,vector<int>& result){
    queue<Node*> q;
    q.push(root);
    Node* node;
    while(!q.empty())
    {
        node = q.front(); //取出队首元素
        q.pop();
        if(!node->has_value) return false;
        if(node->left!=NULL) q.push(node->left); //将此节点的左右子依次加入队列
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
        bool error = false; //标志变量：数据输入是否有错误
        root = newNode();
        //读取一棵树的节点信息
        while(true)
        {   
            if(! (cin >> nodeMsg) ) 
            {
                isReadEnd = true; //若读取结束则跳出
                break;
            }
            if(!strcmp(nodeMsg,"()")) break; //若这颗树的信息已经读取完毕则跳出
            //解析字符串
            int value;
            Node *node = root;
            sscanf(nodeMsg+1,"%d",&value); //获取该节点的value
            char *p = strchr(nodeMsg,',');
            //解析该节点在树中的位置
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
