#include<stdio.h>

int main(){
    char DNAString[51][1001];
    char consensusString[1001];
    int consensusError = 0;
    int T = 0;
    int col,row;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        col = 0;
        row = 0;
        consensusError = 0;
        scanf("%d",&row);
        scanf("%d",&col);
        char ch;
        while((ch = getchar())!='\n');

        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                DNAString[r][c] = getchar();
            }
            while((ch = getchar())!='\n');
        }
        int ANum=0,TNum=0,CNum=0,GNum=0;
        for(int c=0;c<col;c++)
        {
            ANum = 0;
            TNum = 0;
            CNum = 0;
            GNum = 0;
            for(int r=0;r<row;r++)
            {
                switch(DNAString[r][c])
                {
                    case 'A':
                        ANum++;
                        break;
                    case 'T':
                        TNum++;
                        break;
                    case 'C':
                        CNum++;
                        break;
                    case 'G':
                        GNum++;
                        break;
                }
            }
      if(ANum>=CNum)
             {
               if(ANum>=GNum)
               {
                    if(ANum>=TNum)
                    {
                       consensusString[c] = 'A';
                       consensusError = consensusError + (row-ANum);
                    }
                    else{
                       consensusString[c] = 'T';
                       consensusError = consensusError + (row-TNum);
                    }
               }
               else if(GNum>=TNum)
                    {
                        consensusString[c] = 'G';
                        consensusError = consensusError + (row-GNum);
                    }
                    else
                    {
                        consensusString[c] = 'T';
                        consensusError = consensusError + (row-TNum);
                    }
             }
             else if(CNum>=GNum)
                  {
                    if(CNum>=TNum)
                    {
                        consensusString[c] = 'C';
                        consensusError = consensusError + (row-CNum);
                    }
                    else
                    {
                        consensusString[c] = 'T';
                        consensusError = consensusError + (row-TNum);
                    }

                  }
                  else if(GNum>=TNum)
                       {
                            consensusString[c] = 'G';
                            consensusError = consensusError + (row-GNum);
                       }
                       else
                       {
                            consensusString[c] = 'T';
                            consensusError = consensusError + (row-TNum);
                       }
        }
        for(int c=0;c<col;c++)
            printf("%c",consensusString[c]);
        printf("\n");
        printf("%d\n",consensusError);
    }
    return 0;
}
