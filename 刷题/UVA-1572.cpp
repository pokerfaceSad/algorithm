/*
	UVA-1572 
	
	将边看为节点，将方块看为边，构建网络，拓扑排序寻找有向环 
*/
#include<iostream>
#include<cstring>
#include<set>
using namespace std;

int net[52][52]; //A-...Z-A+...Z+
set<int> letterUsed; //出现过的字母
int state[52]; 
void getIndex(char square[],int index[]){
	
	for(int i=0;i<4;i++)
	{
		if(square[2*i] == '0') continue;
		index[i] = square[2*i] - 65 + (square[2*i+1]=='+' ? 26 : 0);
		letterUsed.insert(index[i]);
	}
}
//接收一组输入，构建网络 
bool getInput(){
	int T;
	char square[10]; 
	int index[4]; //方块四条边在网络中的索引 
	if(scanf("%d",&T) != 1) return false;
	else{
		memset(net,0,sizeof(net));
		letterUsed.clear();
		memset(state,0,sizeof(state));
		for(int j=0;j<T;j++)
		{
			cin >> square;
			memset(index,-1,sizeof(index));
			getIndex(square,index);
			for(int i=0;i<4;i++) 
			{
				for(int j=i+1;j<4;j++)
				{
					if(index[i] != -1 && index[j] != -1)   
						net[index[i]][index[j]] = net[index[j]][index[i]] = 1;
				}
			}	
		}
		
	}
	return true;
	
} 
//dfs
bool dfs(int node){
	
	state[node] = -1; //正在探索
	node = (node+26)%52;
	for(set<int>::iterator it=letterUsed.begin();it!=letterUsed.end();it++)
	{
		if(net[node][*it] == 1 && state[*it] != 1)
		{
			if(state[*it] == -1) return false; //若该点也正处于递归栈帧中说明产生了有向环，无解
			else if(!dfs(*it))return false; 
		}
	}
	node = (node+26)%52;
	state[node] = 1; 
	return true;
} 
//拓扑排序 
void topoSort(){
	
	int flag = false;
	for(set<int>::iterator it=letterUsed.begin();it!=letterUsed.end();it++)
	{
		if(state[*it] == 0){ //若该点还未参与排序则进行dfs探索排序 
			if(!dfs(*it)) 
			{
				flag = true; //存在有向环，排序失败 
				break;
			}
		}
	}
		
	if(flag){
		cout << "unbounded" << endl;
	}else{
		cout << "bounded" << endl;
		
	}
}


int main(){
	
	while(getInput())
	{
		topoSort();
	}	
	
	return 0;
} 
