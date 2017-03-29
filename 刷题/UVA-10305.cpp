/*
	UVA10305	拓扑排序 
*/
#include<iostream> 
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

const int maxn = 105;

struct Net{
	int matrix[maxn][maxn];  //邻接矩阵 
	int state[maxn];	//存储节点所处状态 
	int size;
	stack<int> rank;
	Net(){}
}; 

Net* net = new Net();

//接受一组输入构造一个有向无权图
bool getInput(){
	int m,n;
	//初始化矩阵 
	memset(net->matrix,0,sizeof(net->matrix)); 
	memset(net->state,0,sizeof(net->state));
	 
	if(scanf("%d%d",&m,&n) == 2)
	{
		if(!(m || n)) return false; //！！！只判断n=0时WA，估计输入中有无边图 
		net->size = m;
		int from,to; 
		for(int i=0;i<n;i++) 
		{
			scanf("%d%d",&from,&to);
			net->matrix[from-1][to-1] = 1; //！！！注意数组元素与实际对应关系 
		}
		 
		return true;		
	}
	
	//若未读取到m,n说明输入结束 
	return false;
} 

//dfs
bool dfs(int node){
	
	net->state[node] = -1; //正在探索	
	for(int i=0;i<net->size;i++)
	{
		if(net->matrix[node][i] == 1 && net->state[i] != 1)
		{
			if(net->state[i] == -1) return false; //若该点也正处于递归栈帧中说明产生了有向环，无解
			else if(!dfs(i)) return false; 
		}
	}
	
	//将此节点入栈
	net->state[node] = 1; 
	net->rank.push(node); 
	return true;
} 
//拓扑排序 
void topoSort(){
	
	int flag = false;
	for(int i=0;i<net->size;i++)
	{
		if(net->state[i] == 0){ //若该点还未参与排序则进行dfs探索排序 
			if(!dfs(i)) 
			{
				flag = true; //存在有向环，排序失败 
				break;
			}
		}
	}
		
	if(flag){
		printf("No Sulation!");
	}else{
		while(true)
		{
			printf("%d",net->rank.top()+1);
			net->rank.pop();
			if(net->rank.empty()) break;
			printf(" ");
		}
		printf("\n");
	}
}

int main(){
	
	while(getInput())
	{
		topoSort();
	}	
	
	return 0;
}
