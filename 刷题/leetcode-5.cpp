# include <iostream>
# include <string>
# include <utility>
# include <cstring>
using namespace std;

class Solution {
public:
    // 中心扩展
    string expand (int start, int end, string s) {
        int size = s.size();
        while(s[start] == s[end] && start != 0 && end != size-1) {
            if (s[start-1] == s[end+1]) {
                start--;
                end++;
            } else break;
        }
        return s.substr(start, end-start+1);
    }
    string longestPalindrome(string s) {
        string ret = "";
        if (s.size() == 0 || s.size() == 1) return s;
        string tmp;
        int size = s.size();
        for (int start = 0 ; start < size - 1 ; start++) {
            tmp = expand(start, start, s);
            ret = tmp.size() > ret.size() ? tmp : ret;
            if (s[start] == s[start+1]) {
                tmp = expand(start, start + 1, s);
                ret = tmp.size() > ret.size() ? tmp : ret;
            }
        }
        return ret;
    }

    // 动态规划
    string longestPalindrome_dp(string s) {
        string ret = "";
        int size = s.size();
        if (size == 0) return ret;
        int dp[size][size];
        memset(dp, 0, sizeof(dp));
        for (int len = 1 ; len < size+1 ; len++) {
            for (int start = 0 ; start + len - 1 < size ; start++) {
                // 边界条件1
                if (len == 1) dp[start][start] = 1;
                // 边界条件2
                else if (len == 2 && (s[start] == s[start+1])) dp[start][start+1] = 1;
                else {
                    // 状态转移方程
                    dp[start][start+len-1] = dp[start+1][start+len-2] && (s[start] == s[start+len-1]);
                }

                if(dp[start][start+len-1] && len > ret.size()) ret = s.substr(start, len);
            }
        }
        return ret;
    }
};

int main() {
    string str = "a";
    Solution s;
    cout << s.longestPalindrome(str) << endl;
    return 0;
}