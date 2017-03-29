/*
	UVA-10129
	将字母作为节点，单词作为边，判断是否存在欧拉道路 
	判断连通性时忽略方向，判断是否存在欧拉道路时要考虑是入度还是出度 
*/
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1000;

//字母的入度和出度
int inDegree[26];
int outDegree[26];  
//节点的前趋 
int pre[26];
//初始化连通块 
void initPre(){
	for(int i=0;i<26;i++) pre[i] = i;
}
//找到此节点所属连通块的根节点 并进行路径压缩 
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
//将两节点所在的连通块合并 
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
			inDegree[word[size-1]-97]++; //统计入度和出度 
			mix(word[0]-97,word[size-1]-97);
		}
		int unuseNum = 0; //未使用字母数 
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
			//若不连通则无解 
			printf("The door cannot be opened.\n");
			continue;	
		}else{
			//若连通则判断入度和出度
			bool flag = true; 
			int aClassNum = 0,bClassNum = 0; //入度比出度大1和出度比入度大1节点的数目 
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
