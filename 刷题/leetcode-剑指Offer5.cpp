# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // 统计所有的空格
        int count = 0;
        int len = s.size();
        for (auto ch : s) {
            if (ch == ' ') {
                count++;
            }
        }

        s.resize(len + count * 2);

        // 倒序修改，j 追上 i 时所有的空格替换完毕
        for (int i = len - 1, j = s.size() - 1 ; i < j ; i--, j--) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            } else {
                s[j] = s[i];
            }
        }

        return s;
    }
};

int main() {
    return 0;
}