/*
	并查集判断网络连通性 
*/
#include<iostream> 
#include<set>
using namespace std;

const int maxn = 5;

int net[maxn][maxn] =  {0,0,0,0,0,
						0,0,0,1,2,
						0,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //邻接矩阵 
int pre[maxn];
//查找节点所属连通块的首节点 
int find(int node){
	int root = node; 
	while(pre[root] != root)
		root = pre[root];			
	

	//路径压缩 将此节点以上所有节点都挂在此连通块的根节点上  加快下次查询速度 
	int temp;
	while(pre[node] != root)
	{
		temp = pre[node];
		pre[node] = root;
		node = temp;
	}
					
		
	return root;	
}
//连接两节点 将两节点所在连通块的首节点相连 
void mix(int node1,int node2){
	int r1 = find(node1),r2 = find(node2);
	pre[r1] = r2;
}
int main()
{
	
	//初始化所有节点的前趋为自身
	for(int i=0;i<maxn;i++) pre[i] = i;
	//从邻接矩阵中查找边关系
	//因为是无向图因此只查找上三角
	for(int i=0;i<maxn;i++)
	{
		for(int j=i;j<maxn;j++)
		{
			if(net[i][j] != 0) mix(i,j); //若有边连接两节点 
		}
	}
	 
	int num = 0; //连通块数量 
	set<int> rootNodeSet;
	rootNodeSet.clear();
	for(int i=0;i<maxn;i++) 
	{
		rootNodeSet.insert(find(i)); 
	}
	
	cout << rootNodeSet.size() << endl;	//输出连通块数量 
	return 0;
}

