# include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    // dp优化
    // int maxProfit(vector<int>& prices) {
    //     int len = prices.size();
    //     int dp0 = 0, dp1 = -prices[0];
    //     for (int i = 0 ; i < len ; i++) {
    //         dp0 = max(dp0, dp1 + prices[i]);
    //         dp1 = max(dp1, dp0 - prices[i]);
    //     }
    //     return dp0;
    // }
    
    // 没有优化空间复杂度
    // int maxProfit(vector<int>& prices) {
    //     int len = prices.size();
    //     // dp[i][0] 表示第i天不持有股票的收益
    //     // dp[i][1] 表示第i天持有股票的收益
    //     int dp[len][2];
    //     // 第0天不持有股票的收益为0 dp[0][0] = 0
    //     // 第1天持有股票的收益为-prices[0] dp[0][1] = -prices[0]
    //     dp[0][0] = 0; dp[0][1] = -prices[0];
    //     for (int i = 1 ; i < len; i++) {
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    //     }
    //     return dp[len-1][0]; 
    // }
    
    int maxProfit_greedy(vector<int>& prices) {
        int len = prices.size();
        int ans = 0;
        for (int i = 0 ; i < len - 1 ; i++) {
            if (prices[i] < prices[i+1]) {
                ans += (prices[i+1] - prices[i]);
            }
        }
        return ans;
    }
};

int main() {
    int a[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(a, a+6);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}