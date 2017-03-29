/*
	���鼯�ж�������ͨ�� 
*/
#include<iostream> 
#include<set>
using namespace std;

const int maxn = 5;

int net[maxn][maxn] =  {0,0,0,0,0,
						0,0,0,1,2,
						0,0,0,0,1,
						0,1,0,0,1,
						0,2,1,1,0}; //�ڽӾ��� 
int pre[maxn];
//���ҽڵ�������ͨ����׽ڵ� 
int find(int node){
	int root = node; 
	while(pre[root] != root)
		root = pre[root];			
	

	//·��ѹ�� ���˽ڵ��������нڵ㶼���ڴ���ͨ��ĸ��ڵ���  �ӿ��´β�ѯ�ٶ� 
	int temp;
	while(pre[node] != root)
	{
		temp = pre[node];
		pre[node] = root;
		node = temp;
	}
					
		
	return root;	
}
//�������ڵ� �����ڵ�������ͨ����׽ڵ����� 
void mix(int node1,int node2){
	int r1 = find(node1),r2 = find(node2);
	pre[r1] = r2;
}
int main()
{
	
	//��ʼ�����нڵ��ǰ��Ϊ����
	for(int i=0;i<maxn;i++) pre[i] = i;
	//���ڽӾ����в��ұ߹�ϵ
	//��Ϊ������ͼ���ֻ����������
	for(int i=0;i<maxn;i++)
	{
		for(int j=i;j<maxn;j++)
		{
			if(net[i][j] != 0) mix(i,j); //���б��������ڵ� 
		}
	}
	 
	int num = 0; //��ͨ������ 
	set<int> rootNodeSet;
	rootNodeSet.clear();
	for(int i=0;i<maxn;i++) 
	{
		rootNodeSet.insert(find(i)); 
	}
	
	cout << rootNodeSet.size() << endl;	//�����ͨ������ 
	return 0;
}

