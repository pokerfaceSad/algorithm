# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     // dp[i] 表示第i天出售可获取的最大利润
    //     // dp[i] = max(dp[i-1], price[i] - min)
    //     // dp[0] = 0
    //     int len = prices.size();
    //     if (len  == 0) return 0;
    //     vector<int> dp(len, 0);
    //     dp[0] = 0;
    //     int minVal = prices[0];
    //     for (int i = 1 ; i < len; i++) {
    //         minVal = min(minVal, prices[i]);
    //         dp[i] = max(dp[i-1], prices[i] - minVal);
    //     }
    //     return dp[len-1];
    // }

    int maxProfit(vector<int>& prices) {
        // dp[i] 表示第i天出售可获取的最大利润
        // dp[i] = max(dp[i-1], price[i] - min)
        // dp[0] = 0
        int len = prices.size();
        if (len  == 0) return 0;
        int pre = 0;
        int minVal = prices[0];
        for (int i = 1 ; i < len; i++) {
            minVal = min(minVal, prices[i]);
            pre = max(pre, prices[i] - minVal);
        }
        return pre;
    }
};