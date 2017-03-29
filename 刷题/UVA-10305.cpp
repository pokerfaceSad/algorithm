/*
	UVA10305	�������� 
*/
#include<iostream> 
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

const int maxn = 105;

struct Net{
	int matrix[maxn][maxn];  //�ڽӾ��� 
	int state[maxn];	//�洢�ڵ�����״̬ 
	int size;
	stack<int> rank;
	Net(){}
}; 

Net* net = new Net();

//����һ�����빹��һ��������Ȩͼ
bool getInput(){
	int m,n;
	//��ʼ������ 
	memset(net->matrix,0,sizeof(net->matrix)); 
	memset(net->state,0,sizeof(net->state));
	 
	if(scanf("%d%d",&m,&n) == 2)
	{
		if(!(m || n)) return false; //������ֻ�ж�n=0ʱWA���������������ޱ�ͼ 
		net->size = m;
		int from,to; 
		for(int i=0;i<n;i++) 
		{
			scanf("%d%d",&from,&to);
			net->matrix[from-1][to-1] = 1; //������ע������Ԫ����ʵ�ʶ�Ӧ��ϵ 
		}
		 
		return true;		
	}
	
	//��δ��ȡ��m,n˵��������� 
	return false;
} 

//dfs
bool dfs(int node){
	
	net->state[node] = -1; //����̽��	
	for(int i=0;i<net->size;i++)
	{
		if(net->matrix[node][i] == 1 && net->state[i] != 1)
		{
			if(net->state[i] == -1) return false; //���õ�Ҳ�����ڵݹ�ջ֡��˵�����������򻷣��޽�
			else if(!dfs(i)) return false; 
		}
	}
	
	//���˽ڵ���ջ
	net->state[node] = 1; 
	net->rank.push(node); 
	return true;
} 
//�������� 
void topoSort(){
	
	int flag = false;
	for(int i=0;i<net->size;i++)
	{
		if(net->state[i] == 0){ //���õ㻹δ�������������dfs̽������ 
			if(!dfs(i)) 
			{
				flag = true; //�������򻷣�����ʧ�� 
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
