# include <iostream>
# include <string>
using namespace std;

class Solution {
public:

    // KMP
    int* getNext(string str) {
        int size = str.size();
        int* next = new int[size];
        // int next[size];
        next[0] = -1;
        // idx为待计算的next数组元素下标
        // k为idx前面的子串的最大公共前后缀长度
        int idx = 0, k = -1;
        while(idx < size-1) {
            // k为-1 说明 最后一个字符与第一个字符的匹配也失败了
            if (k == -1 || str[idx] == str[k]) {
                next[idx+1] = k + 1;
                k++;
                idx++;
            }
            else k = next[k];
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        int pat_size = needle.size();
        int str_size = haystack.size();
        if (pat_size == 0) return 0;
        if (str_size == 0) return -1;
        if (pat_size > str_size) return -1;
        int* next = getNext(needle);
        int str_idx = 0, pat_idx = 0;
        while (pat_idx < pat_size) {
            if(!(str_idx < str_size)) return -1;
            if (pat_idx == -1 || haystack[str_idx] == needle[pat_idx]) {
                str_idx++;
                pat_idx++;
            }
            else pat_idx = next[pat_idx];
        }
        return str_idx-pat_size;
    }

    // 双指针
    int strStr_v2(string haystack, string needle) {
        int pat_size = needle.size();
        int str_size = haystack.size();
        if (pat_size == 0) return 0;
        if (pat_size > str_size) return -1;
        for (int idx = 0 ; idx < str_size-pat_size+1 ; idx++) {
            for (int start = 0 ; start < pat_size; start++) {
                if (haystack[idx + start] == needle[start]) {
                    if (start == pat_size -1) return idx;
                    else continue;
                } else {
                    break;
                }
            }
        }
        return -1;
    }
};

int main() {
    string str2 = "";
    string str1 = "ab";
    Solution s;
    cout << s.strStr(str1, str2) << endl;
    return 0;
}