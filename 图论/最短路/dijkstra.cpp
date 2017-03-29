/*
	�Ͻ�˹�����㷨�����· 
	
	���ڵ��Ϊ�ҵ����·��visited����δ�ҵ����·��unvisited����������
	length����洢������������ľ��� 
	while(�յ����unvisited����)
	{ 
		��ǰ�ڵ�Ϊ�׽ڵ� 
		�ӵ�ǰ�ڵ㿪ʼ��ͼ����̽�����ҳ���ǰ�ڵ����еĿɴ�ڵ㣬�Ե�ǰ�ڵ����пɴ�ڵ��length�����ɳڲ���
		�ҳ�unvisited��length��̵Ľڵ����visited�������ýڵ���Ϊ��ǰ�ڵ� 
	}

*/
#include<iostream> 
#include<cstring> 
#include<vector>
#include<set>
using namespace std;

const int maxn = 5; //�ڵ��ģ 
const int INF = 10000; //��������� 

int net[maxn][maxn] =  {0,2,1,0,0,
						2,0,0,1,2,
						1,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //�ڽӾ��� 

set<int> visited;	//�Ѿ�̽�õĵ� 
set<int> unvisited; //δ̽�õĵ� 
int length[maxn]; //�ڵ㵽��ʼ��ľ��� 
int fatherNode[maxn]; //���ڵ㼯�� 

void initArray(int array[],int value)
{
	for(int i=0;i<maxn;i++)
		array[i] = value;
}


//��ȡ��ǰ�ڵ�Ŀɴ�ڵ� 
void getReachableNode(int node,vector<int> &reachableNode){
	reachableNode.clear();
	
	for(int i=0;i<maxn;i++)
	{
		if(net[node][i] != 0)	reachableNode.push_back(i);
	}
}
//��length�����ɳڲ���
void relaxationOperate(int node,vector<int> reachableNode){

	for(vector<int>::iterator it = reachableNode.begin();it != reachableNode.end();it++)	
	{
		if(length[*it] > length[node] + net[node][*it])	
		{
			length[*it] = length[node] + net[node][*it];
			fatherNode[*it] = node; //���¸��ڵ㼯��	
		}
		
	}	
}
//��ȡδѰ�ýڵ��о�����̵Ľڵ�
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
	length[node] = 0; //������ע�⣡������û�н��������lengh��Ϊ0��Ӱ���ɳڲ��� 
	
	vector<int> reachableNode;
	int nearestNode;
	 //��ǰ�㷨�Ǵӳ����㿪ʼ�𲽱�������ͼ�����ҵ������㵽���нڵ�����·�� 
	 //����Ҫ�ҵ��յ��ֹͣ��������ѭ��������Ϊ�յ����visited���� 
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
}

int main(){
	int start = 0;
	dijkstra(start);
	
	
	return 0;
}
