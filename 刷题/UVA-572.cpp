#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;

//矩阵规模
int colNum,rowNum;
char matrix[maxn][maxn]; //数据矩阵 
int id[maxn][maxn];  
int idNo;
//搜索节点的周围区域是否连通 
//flag:标志是否正在递归探索同一连通块 
void dfs(int row,int col,int flag){
	if(!flag) 
		id[row][col] = ++idNo;
	else
		id[row][col] = idNo;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			//判断是否出界
			if(row+i>=0 && row+i<rowNum && col+j>=0 && col+j<colNum) 
			{
				if((i!=0 || j!=0) && id[row+i][col+j]==0 && matrix[row+i][col+j] == '@')		dfs(row+i,col+j,1);
			}	
		} 
	}
}
/*
	初始化一组数据 
*/
bool init(){

	cin >> rowNum;
	cin >> colNum;
	//判断是否结束
	if(rowNum==0) return false;
	//初始化id矩阵
	memset(id,0,sizeof(id));
	idNo = 0;
	//输入矩阵
	for(int i=0;i<rowNum;i++) 
	{
		cin >> matrix[i]; 
	}
	//dfs搜索 
	for(int r=0;r<rowNum;r++)	 
	{
		for(int c=0;c<colNum;c++) 
		{
			if(id[r][c]==0 && matrix[r][c]=='@')	dfs(r,c,0);
		} 
	} 
       return true;
}

int main(){
	
	while(init())
	{
		cout << idNo << endl;	
	}
	
	
	return 0;
} 
