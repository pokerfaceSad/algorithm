/*
	ͼbfs�����· 
*/ 
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 5; //�ڵ��ģ 

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //�ڽӾ��� 
					   
int fatherNode[maxn]; //�洢���ɵ�bfs�� 
int length[maxn]; //���ڵ㵽��ʼ��ľ��� 

queue<int> q; //����bfs�Ķ��� 

//��ʼ������ 
void init(int array[],int value){
	for(int i=0;i<maxn;i++)
		array[i] = value;
}

//Ѱ��node�Ŀɴ�ڵ㼯�� 
void getSonNode(int node,vector<int> &sonNodes){
	sonNodes.clear();
	for(int i=0;i<maxn;i++)	
	{
		if(net[node][i] !=  0) 
			sonNodes.push_back(i);	 
	} 
}

//�������ڽڵ㼯�ϣ�����length 
void updateLength(int Node,vector<int> sonNodes){
		
	for(vector<int>::iterator it=sonNodes.begin();it!=sonNodes.end();it++)
	{
		if(length[*it] > length[Node] + net[Node][*it])
		{
			length[*it] = length[Node] + net[Node][*it];
			q.push(*it); //�ӽڵ���� 
			fatherNode[*it] = Node;
		}
	}
}

int main(){
	
	int start = 0;
	
	vector<int> sonNodes;
	memset(fatherNode,-1,sizeof(fatherNode));
	init(length,10000);
	
	length[start] = 0;
	q.push(start);
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		getSonNode(node,sonNodes);
		updateLength(node,sonNodes);	
		
	} 
	
	//������ڵ㼯�� 
	for(int i=0;i<maxn;i++)		
		cout << fatherNode[i] << "  ";
	
	return 0;
}
