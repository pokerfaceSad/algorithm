#include <stdio.h>
#define maxn 200
#define INF 500
void move(int array[],int size,int position);
int judge(int bottom[],int top[]);
void init(int array[]);
void swop(int array1[],int array2[]);
void updateResult(int newResult);

int result;
int main()
{
    int bottom[maxn],bottomSize = 0;
    int top[maxn],topSize = 0;
    
    char ch;
    int flag = 1;
    int num = 1;
	while( ((ch = getchar()) != EOF) && flag)
    {

            result = INF;
            init(bottom);
            init(top);
            bottom[0] = ch - 48;
            bottomSize = 1;
            topSize = 0;
            while((ch = getchar()) != '\n')
            {
                    bottom[bottomSize] = ch - 48;
                    bottomSize++;
            }
            while((ch = getchar()) != '\n')
            {
                    if(ch==EOF)
                    {
                        flag = 0;
                        break;
                    }
                    top[topSize] = ch - 48;
                    topSize++;
            }
            if(bottomSize<topSize)
            {
                int temp;
                swop(top,bottom);
                temp = topSize;
                topSize = bottomSize;
                bottomSize = temp;
            }
            
            for(int p=topSize-1;p>=0;p--)
            {
                move(bottom,bottomSize,p);
                if(judge(bottom,top)) updateResult(bottomSize+p);
                move(bottom,bottomSize,-p); 
            }
            for(int p=1;p<bottomSize;p++)
            {
                move(top,topSize,p);
                if(judge(bottom,top))
                {
                    if(topSize+p-bottomSize>0) updateResult(topSize+p);
                    else updateResult(bottomSize);    
                }
                move(top,topSize,-p);
            }

            if(result==INF)
                printf("%d\n",bottomSize+topSize);
            else
                printf("%d\n",result);

    }
    
	return 0;
}
void move(int array[],int size,int position){
    if(position>0)
    {
        for(int i=size-1;i>=0;i--)
        {       
            array[i+position] = array[i];
            array[i] = 0;
        }    
    }else if(position==0) return;
    else{
        position = -position;
        for(int i=position;i<position+size;i++)
        {       
            array[i-position] = array[i];
            array[i] = 0;
        }    
    }
    
}
int judge(int bottom[],int top[]){
    for(int i=0;i<maxn;i++)
    {
       if((bottom[i]+top[i])>3) 
        {
            return 0;
        }
    } 
    return 1;
}
void swop(int array1[],int array2[]){
    int temp;
    for(int i=0;i<maxn;i++)
    {
        temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
    
}
void init(int array[]){    
    for(int i=0;i<maxn;i++)
    {
        array[i] = 0;
    }
}
void updateResult(int newResult){
   if(newResult<result)
    {
        result = newResult;
    }
}
