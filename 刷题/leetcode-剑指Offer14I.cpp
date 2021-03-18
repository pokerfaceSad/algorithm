# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        // dp[i] 表示长度为i时的最大乘积
        // dp[i] = max(j * dp[i-j], j * (i - j), dp[i])
        // j * dp[i-j] 表示继续剪 j * (i - j) 表示不再剪
        // dp[2] = 1
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3 ; i <= n ; i++) {
            for (int j = 2 ; j < i; j++) {
                dp[i] = max(dp[i], max(j*dp[i-j], j * (i-j)));
            }
        }
        return dp[n];
    }

    // 贪心
    // 根据数学推导 尽可能剪成长度为3的小段
    // 总长度小于4时 最大乘积为n-1
    // 剩余长度小于等于4时 直接停止
    int cuttingRope(int n) {
        if (n < 4) return n-1;
        int res = 1;
        while ( n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};