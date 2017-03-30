#include<iostream> 
#include<cstring>
using namespace std;

const int maxn = 205;

char tree[maxn][maxn]; //�� 
int height; //��ǰ�������ĸ߶� 

//dfs���������ڵ��µ��� 
void dfs(int x,int y){
	cout << tree[x][y] << '(';
	
	if(x+1 < height && tree[x+1][y] == '|')
	{
		//������Ҷ�� �ҵ������ӽڵ�
		//�ҳ��ָ��ߵķ�Χ
		int left=y; //��߽� 
		while(left>=0 && tree[x+2][left] == '-') left--; left++;
		int right = y; //�ұ߽�
		while(right<strlen(tree[x+2]) && !isspace(tree[x+2][right])) right++; right--; 
		for(int i=left;i<=right;i++) 
		{
			if(tree[x+3][i] == '\n') break;  //������ע�⣡�����������о���������ѭ���������ַ�����ĳ�ʼֵ'\0'�ᱻ��Ϊ��Ԫ�� 
			if(tree[x+3][i] != ' ')
			{
				dfs(x+3,i);
			}
		}
	} 
	
	cout << ')';
}
//����һ���� 
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
		while(fgets(tree[height],maxn,stdin)) //fgets���������һ����Ч�ַ���'\n' 
		{
			if(tree[height][0] != '#') height++;
			else break;	
		}
		solve();
	}
	
	return 0;
}
