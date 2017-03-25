#include<stdio.h>

int main(){

    int blank_x = 0;
    int blank_y = 0;
    char puzzle[5][5];
    char c;
    int Num = 0;
    int flag = 0;
    while((c = getchar())!='Z')
    {
        Num++;
        if(Num!=1)
            printf("\n");
        ///读入矩阵

        for(int i=0;i<5;i++)
        {    for(int j=0;j<5;j++)
            {
                if(i==0&&j==0)
                    puzzle[i][j] = c;
                else
                    puzzle[i][j] = getchar();
                    if(puzzle[i][j]=='\n')
                    {
                        puzzle[i][j] = ' ';
                        flag = 1;
                    }
                if(puzzle[i][j]==' ')
                {
                    blank_x = i;
                    blank_y = j;
                }
            }
            ///换行
            if(!flag)
                getchar();
            else
                while(getchar()!='\n');
        }

        ///输出
//        for(int i=0;i<5;i++)
//        {    for(int j=0;j<5;j++)
//            {
//                printf("-%c- ",puzzle[i][j]);
//            }
//            ///换行
//            printf("\n");
//        }


        ///读入命令
        int error = 0;
        char m;
        while((m = getchar())!='0')
        {
            //printf("order:%c",m);
            switch(m)
            {

                case 'A':
                    if(blank_x==0)
                        {
                            error = 1;
                            break;
                        }
                    else
                        {
                            puzzle[blank_x][blank_y] = puzzle[blank_x-1][blank_y];
                            puzzle[blank_x-1][blank_y] = ' ';
                            blank_x = blank_x-1;
                            blank_y = blank_y;
                            break;
                        }
                case 'B':
                    if(blank_x==4)
                        {
                            error = 1;
                            break;
                        }
                    else
                        {
                            puzzle[blank_x][blank_y] = puzzle[blank_x+1][blank_y];
                            puzzle[blank_x+1][blank_y] = ' ';
                            blank_x = blank_x+1;
                            blank_y = blank_y;
                            break;
                        }
                case 'R':
                    if(blank_y==4)
                       {
                            error = 1;
                            break;
                       }

                    else
                       {
                            puzzle[blank_x][blank_y] = puzzle[blank_x][blank_y+1];
                            puzzle[blank_x][blank_y+1] = ' ';
                            blank_x = blank_x;
                            blank_y = blank_y+1;
                            break;
                       }

                case 'L':
                    if(blank_y==0)
                       {
                            error = 1;
                            break;
                       }

                    else
                       {
                            puzzle[blank_x][blank_y] = puzzle[blank_x][blank_y-1];
                            puzzle[blank_x][blank_y-1] = ' ';
                            blank_x = blank_x;
                            blank_y = blank_y-1;
                            break;
                       }
                case '\n':
                    break;
                default:
                    error = 1;
                    break;
            }

        }
        ///回车
        getchar();
        ///输出结果
        printf("Puzzle #%d:\n",Num);
        if(error)
            printf("This puzzle has no final configuration.\n");
        else
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    printf("%c",puzzle[i][j]);
                    if(j!=4)
                        printf(" ");
                    else
                        printf("\n");
                }
            }
    }


    return 0;
}
