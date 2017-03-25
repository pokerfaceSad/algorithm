#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 100000 + 5;

int main(){
    
    string line;

    char letters[maxn];  //����Ԫ�� ����Ԫ�����գ���letters[1]��ʼ�洢
    int next[maxn]; //�洢�����������Ϣ
    int last; //�洢�����е�ĩ�˽ڵ�
    int cur; //��ǰԪ���������е�ǰ��
    int len; //����Ԫ�صĸ���
    while(cin >> letters+1){
        /**
         * ��ʼ��������Ϣ
         * */
        last = cur = 0;
        next[0] = last;
        len = strlen(letters+1); 
        
        for(int i=1;i<=len;i++)
        {
            if(letters[i] == '[') cur = 0;
            else if(letters[i] == ']') cur = last;
            else{
                /**
                 * ����ǰԪ��letters[i]���뵽letters[cur]��letters[next[cur]]֮��
                 * */
                next[i] = next[cur];
                next[cur] = i;
                if(cur==last) last = i; //����ǰ�ڵ��ǰ����ĩ�ˣ������ĩ��
                cur = i; //��ǰ�ڵ������ϣ���һ���ڵ��ǰ��Ϊ��ǰ���
            }
        }
        //���
        int index = 0;
        while(1)
        {
            index = next[index];
            cout << letters[index];
            if(index==last) break;
        }
        cout << endl;
    }
    return 0;    
}
