#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 就地翻转
    // 两个指针 index用于为新的字符串赋值 ptr用于操作原来的字符串
    string reverseWords(string s)
    {
        int size = s.size();
        reverse(s.begin(), s.end());
        int index = 0;
        for (int ptr = 0; ptr < size; ptr++)
        {
            if (s[ptr] != ' ')
            {
                if (index != 0) s[index++] = ' ';
                int start=index;
                while (ptr < size && s[ptr] != ' ') s[index++] = s[ptr++];
                reverse(s.begin() + start, s.begin() + index); // Reverses the order of the elements in the range [first,last)
            }
        }
        if (index < size)
            s.erase(s.begin() + index, s.end()); // Removes the characters in the range [first,last) from this string.
        return s;
    }
    // 借助stack
    string reverseWords_stack(string s)
    {
        int start = 0, end = s.size() - 1;
        // 去掉首尾空格
        while (start <= end && s[start] == ' ')
            start++;
        while (start <= end && s[end] == ' ')
            end--;
        if (start > end)
            return "";
        // 入栈
        stack<string> st;
        string word;
        while (start <= end)
        {
            if (s[start] != ' ')
                word += s[start];
            else if ((s[start] == ' ') && word.size() != 0)
            {
                st.push(move(word));
                word = "";
            }
            start++;
        }
        if (word.size() != 0)
            st.push(move(word));
        string ret;
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
            if (st.empty())
                break;
            ret += " ";
        }
        return ret;
    }
};


int main()
{
    string str = "123 123";
    Solution s;
    string ret = s.reverseWords(str);
    cout << ret << endl;
    // string str = "123";
    // str.erase(str.begin() + 5);
    // cout << str << endl;
    return 0;
}