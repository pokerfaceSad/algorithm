#include<iostream> 
#include<cstring>
using namespace std;

const int maxn = 200;
int sum[maxn]; //某一列的权值之和 
/*
	递归读取一颗树的权值，并存入sum的pos位置 
*/
void build(int pos){ 
//	cout << "new Thread pos:" << pos << endl;
	int v; 
	cin >> v;
//	cout << "Input:" << v << endl; 
	if(v==-1) 
	{
//		cout << "return" << endl;
		return;//若读取到的值为-1则该树结束 
	}
	//否则应继续读取它的左子树和右子树
	sum[pos] += v;
	build(pos-1);
	build(pos+1);
	
	return;
} 
/*
	处理一棵树 
*/
bool init(){
	//初始化sum
	memset(sum,0,sizeof(sum));
	//输入根节点
	int v;
	int pos = maxn/2; //根节点的初始位置 
	cin >> v;
//	cout << "Input:" << v << endl; 
	if(v==-1) return false; 
	sum[pos] = v;
	//读取
	build(pos-1); //读取根节点的左子树
	build(pos+1); //读取根节点的右子树 
	return true;
}
int main(){
	int no = 0; 
	while(init())
	{
		no++;
		//输出sum
		int p = 0;
		while(sum[p] == 0) p++; //找出最左边叶子的位置
		cout <<  "Case " << no << ":\n" << sum[p];
		while(sum[++p] != 0)
		{
			cout << " " << sum[p]; 
		}
		cout << endl << endl;
		
	}

	return 0;

} 
