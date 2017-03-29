/*
	UVA-10129
	����ĸ��Ϊ�ڵ㣬������Ϊ�ߣ��ж��Ƿ����ŷ����· 
	�ж���ͨ��ʱ���Է����ж��Ƿ����ŷ����·ʱҪ��������Ȼ��ǳ��� 
*/
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1000;

//��ĸ����Ⱥͳ���
int inDegree[26];
int outDegree[26];  
//�ڵ��ǰ�� 
int pre[26];
//��ʼ����ͨ�� 
void initPre(){
	for(int i=0;i<26;i++) pre[i] = i;
}
//�ҵ��˽ڵ�������ͨ��ĸ��ڵ� ������·��ѹ�� 
int find(int node){
	int root = node;
	while(pre[root] != root)
		root = pre[root];
	
	int temp;
	while(pre[node] != root)
	{
		temp = pre[node];
		pre[node] = root;
		node = temp;
	}
	
	return root;
}
//�����ڵ����ڵ���ͨ��ϲ� 
void mix(int node1,int node2){
	int r1 = find(node1),r2 = find(node2);
	pre[r1] = r2;
}
int main(){
	int T,N;
	cin >> T;
	char word[maxn];
	for(int i=0;i<T;i++)
	{
		memset(inDegree,0,sizeof(inDegree));
		memset(outDegree,0,sizeof(outDegree));
		initPre();
		cin >> N;
		for(int j=0;j<N;j++)
		{
			cin >> word;
			int size = strlen(word);
			outDegree[word[0]-97]++; 
			inDegree[word[size-1]-97]++; //ͳ����Ⱥͳ��� 
			mix(word[0]-97,word[size-1]-97);
		}
		int unuseNum = 0; //δʹ����ĸ�� 
		for(int l=0;l<26;l++) 
		{
			if(inDegree[l] == 0 && outDegree[l] == 0) unuseNum++; 
		} 
		int rootNodeNum = 0;
		for(int k=0;k<26;k++) 
		{
			if(pre[k] == k) rootNodeNum++;  
		}
		if(rootNodeNum-unuseNum != 1) 
		{
			//������ͨ���޽� 
			printf("The door cannot be opened.\n");
			continue;	
		}else{
			//����ͨ���ж���Ⱥͳ���
			bool flag = true; 
			int aClassNum = 0,bClassNum = 0; //��ȱȳ��ȴ�1�ͳ��ȱ���ȴ�1�ڵ����Ŀ 
			for(int m=0;m<26;m++) 
			{
				switch(inDegree[m]-outDegree[m])
				{
					case 0: break;
					case 1: aClassNum++; break;
					case -1: bClassNum++; break;
					default : flag = false;
				}	
			}
			if(!((aClassNum==1&&bClassNum==1) ||  (aClassNum==0&&bClassNum==0))) flag = false;
			if(flag) printf("Ordering is possible.\n");
			else printf("The door cannot be opened.\n");
		} 
	}
	
	
	return 0;
} 
