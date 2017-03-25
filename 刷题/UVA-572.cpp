#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;

//�����ģ
int colNum,rowNum;
char matrix[maxn][maxn]; //���ݾ��� 
int id[maxn][maxn];  
int idNo;
//�����ڵ����Χ�����Ƿ���ͨ 
//flag:��־�Ƿ����ڵݹ�̽��ͬһ��ͨ�� 
void dfs(int row,int col,int flag){
	if(!flag) 
		id[row][col] = ++idNo;
	else
		id[row][col] = idNo;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			//�ж��Ƿ����
			if(row+i>=0 && row+i<rowNum && col+j>=0 && col+j<colNum) 
			{
				if((i!=0 || j!=0) && id[row+i][col+j]==0 && matrix[row+i][col+j] == '@')		dfs(row+i,col+j,1);
			}	
		} 
	}
}
/*
	��ʼ��һ������ 
*/
bool init(){

	cin >> rowNum;
	cin >> colNum;
	//�ж��Ƿ����
	if(rowNum==0) return false;
	//��ʼ��id����
	memset(id,0,sizeof(id));
	idNo = 0;
	//�������
	for(int i=0;i<rowNum;i++) 
	{
		cin >> matrix[i]; 
	}
	//dfs���� 
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
