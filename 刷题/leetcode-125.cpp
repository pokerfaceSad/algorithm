# include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 双指针
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            // 若不是字符则跳过
            if (!isLetterOrNum(s[head])) {
                head++;
                continue;
            }
            if (!isLetterOrNum(s[tail])) {
                tail--;
                continue;
            }
            // 若是大写字符则转换为小写
            if (isUpper(s[head])) {
                s[head] = s[head] - 'A' + 'a';
            }
            if (isUpper(s[tail])) {
                s[tail] = s[tail] - 'A' + 'a';
            }
            if (s[head] == s[tail]) {
                head++;
                tail--;
            } else return false;
        }
        return true;
    }

    bool isUpper(char ch) {
        if (ch >= 'A' && ch <= 'Z') return true;
        else return false;
    }

    bool isLetterOrNum(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("0p") << endl;
    return 0;
}