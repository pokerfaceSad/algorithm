# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool isEqual(char ch1, char ch2) {
        if (ch1 == ch2 || ch2 == '.') return true;
        else return false;
    }

    bool isMatch(string s, string p) {
        // dp[i][j] 表示s前i个字符和p前j个字符能否匹配
        // 递推关系
        // 若p第j个字符是小写字母 f[i][j] = f[i-1][j-1] && s[i] == p[j]
        // 若p的第j个字符是*
        //      s[i] != p[j-1] f[i][j] = f[i][j-2]
        //      s[i] == p[j-1] f[i][j] = f[i-1][j]
        
    }
};

int main() {
    Solution s;
    s.isMatch("aaa", "ab*a*c*a");
    return 0;
}