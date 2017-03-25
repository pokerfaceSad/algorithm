#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 100000 + 5;

int main(){
    
    string line;

    char letters[maxn];  //数据元素 将首元素留空，从letters[1]开始存储
    int next[maxn]; //存储链表的链接信息
    int last; //存储链表中的末端节点
    int cur; //当前元素在链表中的前趋
    int len; //数据元素的个数
    while(cin >> letters+1){
        /**
         * 初始化链接信息
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
                 * 将当前元素letters[i]插入到letters[cur]和letters[next[cur]]之间
                 * */
                next[i] = next[cur];
                next[cur] = i;
                if(cur==last) last = i; //若当前节点的前趋是末端，则更新末端
                cur = i; //当前节点操作完毕，下一个节点的前趋为当前结点
            }
        }
        //输出
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
