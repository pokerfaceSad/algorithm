/*
	Date: 16/03/17 11:47
	Description: 用数组存储节点关系的方式建立二叉树 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
	value按照从上到下从左至右的方向赋值 
*/
int value[10]; 
int leftNode[10];
int rightNode[10];	

void bfs(vector<int>& output);

void init(int array[],int size){
	for(int i=0;i<size;i++)
		array[i] = -1; 
}
int main(){



	init(value,10);
	init(leftNode,10);
	init(rightNode,10);
	
	value[0] = 0; value[1] = 1; value[2] = 2; 
	value[3] = 3; value[4] = 4; value[5] = 5; value[6] = 6; 
	
	
	leftNode[0] = 1; rightNode[0] = 2;
	leftNode[1] = 3; rightNode[1] = 4;
	leftNode[2] = 5; rightNode[2] = 6;
	
	vector<int> output;
	bfs(output);
	for(vector<int>::iterator it = output.begin();it != output.end();it++)
		cout << *it << " ";
	 
	 
	
} 

/*
	bfs宽度优先搜索 
	
*/ 
void bfs(vector<int> &output)
{
	queue<int> q; 
	int nodeNo;
	q.push(0);
	output.clear();
	while(!q.empty()){
		nodeNo = q.front();
		q.pop(); 
		output.push_back(value[nodeNo]);
		if(leftNode[nodeNo] != -1) q.push(leftNode[nodeNo]);
		if(rightNode[nodeNo] != -1) q.push(rightNode[nodeNo]); 
	}
	
}
