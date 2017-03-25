#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    
    
    vector<int> wordsLenth[1000];
    vector<string> words[1000];
    //读取每一行
    string line = "";
    int lineNum = 0;
    while(getline(cin,line))
    {
        lineNum ++;
        //从每一行中读取每一个词
        string str;
        stringstream ss(line);
        while(ss >> str) 
        {
            wordsLenth[lineNum-1].push_back(str.length());
            words[lineNum-1].push_back(str);
        }
        
    }
    //找出列数
    int colNum = 0;
    for(int i=0;i<lineNum;i++)
    {
        colNum = colNum>=wordsLenth[i].size() ? colNum : wordsLenth[i].size();
    }
    int colSize[colNum]; //存储每一列所占位长度
    for(int i=0;i<colNum;i++) colSize[i]=0;   
  
    //找出每一列中最长的
    for(int i=0;i<colNum;i++)
    {
        //循环每一行
        for(int j=0;j<lineNum;j++)
        {
            if(wordsLenth[j].size()>=i+1)
            {
                colSize[i] = colSize[i]>wordsLenth[j][i] ? colSize[i] : wordsLenth[j][i]+1;
            }
        }
    }
    
    //输出
//    int no = 0;
    for(int i=0;i<lineNum;i++)
    {
//        no++;
//        if(no!=1)
//            cout<<endl;
        for(int j=0;j<colNum;j++)
        {
            if(words[i].size()>j)
            {
                cout << words[i][j];
                //输出空格
                if(j+1!=words[i].size())
                    for(int k=0;k<colSize[j]-wordsLenth[i][j];k++) cout << " ";
            }
        }
        cout<<endl;
    }
    /*
    cout <<"lineNum:"<< lineNum <<endl;
    for(int i=0;i<lineNum;i++)
    {
        for(vector<int>::iterator it = wordsLenth[i].begin();it!=wordsLenth[i].end();it++)
        {
            cout << *it << " ";
        }
        cout<<"\n";
    }    
    
    cout <<"colNum:"<< colNum <<endl;
    for(int i=0;i<colNum;i++)
    {
        cout << colSize[i] << "  ";
    } */           
    
}
