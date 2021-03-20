# include <iostream>
# include<vector>
using namespace std;

class Solution {
public:
    // int translateNum(int num) {
    //     // dp[i] 表示前i个字符的翻译方案数
    //     // dp[i] = isMakeSense() ? dp[i-1] + dp[i-2] : dp[i-1]
    //     // dp[0] = 1 dp[1] = 1
    //     string str = to_string(num);
    //     int len = str.size();
    //     if (len < 2) return 1;
    //     vector<int> dp(len+1, 0);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2 ; i <= len ; i++) {
    //         dp[i] = isMakeSense(str.substr(i-2, 2)) ? dp[i-1] + dp[i-2] : dp[i-1];
    //     }
    //     return dp[len];
    // }
    int translateNum(int num) {
        // dp[i] 表示前i个字符的翻译方案数
        // dp[i] = isMakeSense() ? dp[i-1] + dp[i-2] : dp[i-1]
        // dp[0] = 1 dp[1] = 1
        string str = to_string(num);
        int len = str.size();
        if (len < 2) return 1;
        int prepre = 1;
        int pre = 1;
        int tmp;
        for (int i = 2 ; i <= len ; i++) {
            tmp = pre;
            pre = isMakeSense(str.substr(i-2, 2)) ? prepre + pre : pre;
            prepre = tmp;
        }
        return pre;
    }
    bool isMakeSense(string str) {
        return str >= "10" && str <= "25";
    }
};

int main() {
    Solution s;
    cout << s.translateNum(25) << endl;
    return 0;
}