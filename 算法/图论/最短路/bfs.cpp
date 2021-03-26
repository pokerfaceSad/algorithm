/*
	图bfs求最短路 
*/ 
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 5; //节点规模 

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵 
					   
int fatherNode[maxn]; //存储生成的bfs树 
int length[maxn]; //各节点到初始点的距离 

queue<int> q; //控制bfs的队列 

//初始化数组 
void init(int array[],int value){
	for(int i=0;i<maxn;i++)
		array[i] = value;
}

//寻找node的可达节点集合 
void getSonNode(int node,vector<int> &sonNodes){
	sonNodes.clear();
	for(int i=0;i<maxn;i++)	
	{
		if(net[node][i] !=  0) 
			sonNodes.push_back(i);	 
	} 
}

//遍历相邻节点集合，更新length 
void updateLength(int Node,vector<int> sonNodes){
		
	for(vector<int>::iterator it=sonNodes.begin();it!=sonNodes.end();it++)
	{
		if(length[*it] > length[Node] + net[Node][*it])
		{
			length[*it] = length[Node] + net[Node][*it];
			q.push(*it); //子节点入队 
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
	
	//输出父节点集合 
	for(int i=0;i<maxn;i++)		
		cout << fatherNode[i] << "  ";
	
	return 0;
}
