/*
	UVA-1572 
	
	���߿�Ϊ�ڵ㣬�����鿴Ϊ�ߣ��������磬��������Ѱ������ 
*/
#include<iostream>
#include<cstring>
#include<set>
using namespace std;

int net[52][52]; //A-...Z-A+...Z+
set<int> letterUsed; //���ֹ�����ĸ
int state[52]; 
void getIndex(char square[],int index[]){
	
	for(int i=0;i<4;i++)
	{
		if(square[2*i] == '0') continue;
		index[i] = square[2*i] - 65 + (square[2*i+1]=='+' ? 26 : 0);
		letterUsed.insert(index[i]);
	}
}
//����һ�����룬�������� 
bool getInput(){
	int T;
	char square[10]; 
	int index[4]; //�����������������е����� 
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
	
	state[node] = -1; //����̽��
	node = (node+26)%52;
	for(set<int>::iterator it=letterUsed.begin();it!=letterUsed.end();it++)
	{
		if(net[node][*it] == 1 && state[*it] != 1)
		{
			if(state[*it] == -1) return false; //���õ�Ҳ�����ڵݹ�ջ֡��˵�����������򻷣��޽�
			else if(!dfs(*it))return false; 
		}
	}
	node = (node+26)%52;
	state[node] = 1; 
	return true;
} 
//�������� 
void topoSort(){
	
	int flag = false;
	for(set<int>::iterator it=letterUsed.begin();it!=letterUsed.end();it++)
	{
		if(state[*it] == 0){ //���õ㻹δ�������������dfs̽������ 
			if(!dfs(*it)) 
			{
				flag = true; //�������򻷣�����ʧ�� 
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
