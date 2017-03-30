#include<iostream> 
#include<cstring>
using namespace std;

const int maxn = 205;

char tree[maxn][maxn]; //树 
int height; //当前处理树的高度 

//dfs输出此坐标节点下的树 
void dfs(int x,int y){
	cout << tree[x][y] << '(';
	
	if(x+1 < height && tree[x+1][y] == '|')
	{
		//若不是叶子 找到所有子节点
		//找出分割线的范围
		int left=y; //左边界 
		while(left>=0 && tree[x+2][left] == '-') left--; left++;
		int right = y; //右边界
		while(right<strlen(tree[x+2]) && !isspace(tree[x+2][right])) right++; right--; 
		for(int i=left;i<=right;i++) 
		{
			if(tree[x+3][i] == '\n') break;  //！！！注意！！！遇到换行就跳出本轮循环，否则字符数组的初始值'\0'会被认为是元素 
			if(tree[x+3][i] != ' ')
			{
				dfs(x+3,i);
			}
		}
	} 
	
	cout << ')';
}
//处理一棵树 
void solve(){
	
	cout << '(';
	for(int i=0;i<strlen(tree[0]);i++) 
	{
		if(tree[0][i] != ' ') 
		{	
			if(tree[0][i] == '#') break;
			dfs(0,i);
			break;
		}
	}
	cout << ")\n";
} 



int main(){
	
	int T;
	cin >> T;
	while(getchar() != '\n');
	for(int i=0;i<T;i++)
	{
		height = 0;
		memset(tree,'\0',sizeof(tree));
		while(fgets(tree[height],maxn,stdin)) //fgets读出的最后一个有效字符是'\n' 
		{
			if(tree[height][0] != '#') height++;
			else break;	
		}
		solve();
	}
	
	return 0;
}
