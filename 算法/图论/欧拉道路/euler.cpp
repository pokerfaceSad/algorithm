/*
	从无向图中的一个结点出发走出一条道路，每条边恰好经过一次，这样的路线称为欧拉道路（eulerian path）
	如果一个无向图是连通的，且最多只有两个奇点，则一定存在欧拉道路。如果有两个奇点，则必须从其中一个
	奇点出发，另一个奇点终止；如果奇点不存在，则可以从任意点出发，最终一定会回到该点（称为欧拉回路）。
	
	对于有向图：若此图忽略方向后图是连通的，并且，最多只能有两个点的入读不等于初度，而且必须是其中一个点的出度比入度大1（起点），另一个
	点的入度比出度大1（终点）。 
	 

	可以用连通性和度数判断是否存在欧拉道路
	用DFS构建欧拉道路 
*/
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 5;

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵
int degree[maxn]; //节点的度
int isNodeVisited[maxn];
void DFS(int node){
	isNodeVisited[node] = 1;
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] != 0 && isNodeVisited[i] == 0) DFS(i);
	}
} 

int isEdgeVisited[maxn][maxn];
//DFS求欧拉道路 
void euler(int node){
	
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] && !isEdgeVisited[node][i]) 
		{
			isEdgeVisited[node][i] = isEdgeVisited[i][node] = 1; //若是有向图则只修改一条边 
			cout << "from:" << node << endl;
			cout << "to:" << i << endl << endl;
			euler(i);
		}
	} 
	
	
}
int main(){
	//DFS判断连通性
	memset(isNodeVisited,0,sizeof(isNodeVisited));
	DFS(0);
	bool flag = true;
	for(int i=0;i<maxn;i++)	 
	{
		if(isNodeVisited[i] != 1) flag = false;
	}	
	if(!flag)
	{
		cout << "net is unconnected!" << endl;
		return 0;
	}
	memset(degree,0,sizeof(degree));
	for(int i=0;i<maxn;i++) 
	{
		for(int j=0;j<maxn;j++)
		{
			if(net[i][j] != 0) degree[i]++;
		}
	}
	//统计奇度点的个数
	int cout = 0; 
	int oddDegreeNode;
	for(int i=0;i<maxn;i++) 
	{
		if(degree[i]%2 == 1) 
		{
			oddDegreeNode = i;
			cout++;
		}
	}
	//求欧拉道路 
	memset(isEdgeVisited,0,sizeof(isEdgeVisited)); 
	switch(cout)
	{
		case 0: 
			euler(0);
			break; 
		case 2: 
			euler(oddDegreeNode); 
			break;
		default: break;
	}
	
	return 0;
} 
