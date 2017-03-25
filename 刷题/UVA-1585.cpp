#include<stdio.h> 
#include<string.h>
int main(){
	
	int c;
	int ONum = 0,score = 0;
	int T = 0;
	char s[85];
	scanf("%d",&T);
	int i = 0,j = 0;
	for(i=0;i<T;i++)
	{
		ONum = 0;
		score = 0;
		scanf("%s",s);
		for(j = 0;j<strlen(s);j++)
		{
			if(s[j]=='O')
			{
				ONum++;
				score = score+ONum;
			}
			else{
				ONum = 0;
			}
		}
		printf("%d\n",score); 
		
	}
	return 0;
}
