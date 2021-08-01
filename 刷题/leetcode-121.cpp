# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // 只允许交易一次
    // int maxProfit(vector<int>& prices) {
    //     int len = prices.size();
    //     int dp[len][2];
    //     dp[0][0] = 0; dp[0][1] = -prices[0];
    //     for (int i = 1 ; i < len ; i++) {
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    //         dp[i][1] = max(dp[i-1][1], -prices[i]); // 因为只允许一次买入，所以dp[i][1]只能从dp[i-1][0] == 0的情况转化而来
    //     }
    //     return dp[len - 1][0];
    // }

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int dp0, dp1;
        dp0 = 0; dp1 = -prices[0];
        for (int i = 1 ; i < len ; i++) {
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, -prices[i]);
        }
        return dp0;
    }
};

int main() {
    return 0;
}