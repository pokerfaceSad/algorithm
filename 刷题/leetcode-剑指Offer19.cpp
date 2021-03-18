# include <iostream>
# include <string>
# include <vector>
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
        //      若*前的字符可以和s[i]匹配，则直接考虑去掉s[:i-1]能不能和p[:j]匹配，或s[:i]能不能和p[:j-2]匹配
        //      s[i] == p[j-1] f[i][j] = f[i-1][j]
        // dp[0][0] = 1;
        // 空的模式串除了空的字符串匹配不到任何字符串 除了dp[0][0]外 dp[x][0] = 0
        // 空的字符串只能可能被以*结尾的模式串匹配
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0 ; i <= m ; i++) {
            // 空的模式串除了空的字符串匹配不到任何字符串，因此j从1开始循环
            for (int j = 1 ; j <= n ; j++) {
                if (p[j-1] != '*') {
                    // 空的字符串只能可能被以*结尾的模式串匹配，因此短路与i>0
                    dp[i][j] = (i > 0) && dp[i-1][j-1] && isEqual(s[i-1], p[j-1]);
                } else {
                    if (i>0 && isEqual(s[i-1], p[j-2])) dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "a*") << endl;
    return 0;
}