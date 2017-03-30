/*
	������ͼ�е�һ���������߳�һ����·��ÿ����ǡ�þ���һ�Σ�������·�߳�Ϊŷ����·��eulerian path��
	���һ������ͼ����ͨ�ģ������ֻ��������㣬��һ������ŷ����·�������������㣬����������һ��
	����������һ�������ֹ�������㲻���ڣ�����Դ���������������һ����ص��õ㣨��Ϊŷ����·����
	
	��������ͼ������ͼ���Է����ͼ����ͨ�ģ����ң����ֻ�������������������ڳ��ȣ����ұ���������һ����ĳ��ȱ���ȴ�1����㣩����һ��
	�����ȱȳ��ȴ�1���յ㣩�� 
	 

	��������ͨ�ԺͶ����ж��Ƿ����ŷ����·
	��DFS����ŷ����· 
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
						0,2,1,1,0}; //�ڽӾ���
int degree[maxn]; //�ڵ�Ķ�
int isNodeVisited[maxn];
void DFS(int node){
	isNodeVisited[node] = 1;
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] != 0 && isNodeVisited[i] == 0) DFS(i);
	}
} 

int isEdgeVisited[maxn][maxn];
//DFS��ŷ����· 
void euler(int node){
	
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] && !isEdgeVisited[node][i]) 
		{
			isEdgeVisited[node][i] = isEdgeVisited[i][node] = 1; //��������ͼ��ֻ�޸�һ���� 
			cout << "from:" << node << endl;
			cout << "to:" << i << endl << endl;
			euler(i);
		}
	} 
	
	
}
int main(){
	//DFS�ж���ͨ��
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
	//ͳ����ȵ�ĸ���
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
	//��ŷ����· 
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
