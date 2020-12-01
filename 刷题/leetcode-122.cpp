# include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    // dp
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 0 ; i < len ; i++) {
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, dp0 - prices[i]);
        }
        return dp0;
    }
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
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(1);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}