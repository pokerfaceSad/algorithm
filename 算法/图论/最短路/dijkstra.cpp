/*
	迪杰斯特拉算法求最短路 
	
	将节点分为找到最短路（visited）和未找到最短路（unvisited）两个集合
	length数组存储各点距离出发点的距离 
	while(终点进入unvisited集合)
	{ 
		当前节点为首节点 
		从当前节点开始对图进行探索，找出当前节点所有的可达节点，对当前节点所有可达节点的length进行松弛操作
		找出unvisited中length最短的节点加入visited，并将该节点设为当前节点 
	}

*/
#include<iostream> 
#include<cstring> 
#include<vector>
#include<set>
using namespace std;

const int maxn = 5; //节点规模 
const int INF = 10000; //定义无穷大 

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵 

set<int> visited;	//已经探访的点 
set<int> unvisited; //未探访的点 
int length[maxn]; //节点到初始点的距离 
int fatherNode[maxn]; //父节点集合 

void initArray(int array[],int value)
{
	for(int i=0;i<maxn;i++)
		array[i] = value;
}


//获取当前节点的可达节点 
void getReachableNode(int node,vector<int> &reachableNode){
	reachableNode.clear();
	
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] != 0)	reachableNode.push_back(i);
	}
}
//对length进行松弛操作
void relaxationOperate(int node,vector<int> reachableNode){

	for(vector<int>::iterator it = reachableNode.begin();it != reachableNode.end();it++)	
	{
		if(length[*it] > length[node] + net[node][*it])	
		{
			length[*it] = length[node] + net[node][*it];
			fatherNode[*it] = node; //更新父节点集合	
		}
		
	}	
}
//获取未寻访节点中距离最短的节点
int getNearestNode(){

	int nearestNode = *(unvisited.begin());
	for(set<int>::iterator it = unvisited.begin();it != unvisited.end();it++)
	{
		if(length[*it] < length[nearestNode] ) nearestNode = *it;
	}
	
	return nearestNode;
} 

void dijkstra(int start){
	
	int node = start;
	
	initArray(length,INF);
	initArray(fatherNode,-1);
	for(int i=0;i<maxn;i++)	
	{
		unvisited.insert(i);
	}
	
	unvisited.erase(unvisited.find(node));
	visited.insert(node);
	length[node] = 0; //！！！注意！！！若没有将出发点的lengh设为0则将影响松弛操作 
	
	vector<int> reachableNode;
	int nearestNode;
	 //当前算法是从出发点开始逐步遍历整个图，即找到出发点到所有节点的最短路径 
	 //若是要找到终点就停止，则将跳出循环条件设为终点进入visited集合 
	while(!unvisited.empty())
	{
		getReachableNode(node,reachableNode);
		relaxationOperate(node,reachableNode);
		nearestNode = getNearestNode();
		unvisited.erase(unvisited.find(nearestNode));
		visited.insert(nearestNode);
		
		node = nearestNode;
	}
	
	for(int i=0;i<maxn;i++)
		cout << fatherNode[i] << "  ";
	for(int i=0;i<maxn;i++)
		cout << length[i] << "  ";
}

int main(){
	int start = 0;
	dijkstra(start);
	
	
	return 0;
}
