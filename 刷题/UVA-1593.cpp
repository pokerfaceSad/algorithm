#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    
    
    vector<int> wordsLenth[1000];
    vector<string> words[1000];
    //��ȡÿһ��
    string line = "";
    int lineNum = 0;
    while(getline(cin,line))
    {
        lineNum ++;
        //��ÿһ���ж�ȡÿһ����
        string str;
        stringstream ss(line);
        while(ss >> str) 
        {
            wordsLenth[lineNum-1].push_back(str.length());
            words[lineNum-1].push_back(str);
        }
        
    }
    //�ҳ�����
    int colNum = 0;
    for(int i=0;i<lineNum;i++)
    {
        colNum = colNum>=wordsLenth[i].size() ? colNum : wordsLenth[i].size();
    }
    int colSize[colNum]; //�洢ÿһ����ռλ����
    for(int i=0;i<colNum;i++) colSize[i]=0;   
  
    //�ҳ�ÿһ�������
    for(int i=0;i<colNum;i++)
    {
        //ѭ��ÿһ��
        for(int j=0;j<lineNum;j++)
        {
            if(wordsLenth[j].size()>=i+1)
            {
                colSize[i] = colSize[i]>wordsLenth[j][i] ? colSize[i] : wordsLenth[j][i]+1;
            }
        }
    }
    
    //���
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
                //����ո�
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
