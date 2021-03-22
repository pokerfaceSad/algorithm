# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // dp[n][x] 表示n个色子时，和为x的可能出现的情况数
        // dp[n][x] = dp[n-1][x-1] + dp[n-1][x-2] + dp[n-1][x-3] + ... + dp[n-1][x-6]
        // 总的情况数 pow(6, n)
        // dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1, .... , dp[0][5] = 1
        vector<vector<int>> dp(n, vector<int>(6*n, 0));
        for (int i = 0 ; i < 6 ; i++) dp[0][i] = 1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; (j+1) <= 6*(i+1) ; j++) {
                if (j < i) {
                    dp[i][j] = 0;
                    continue;
                }
                for (int k = 1 ; j-k > 0 ; k++) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        int total = pow(6, n);
        vector<double> res;
        for (auto num : dp[n-1]) {
            if (num == 0) continue;
            res.push_back(num/total);
        }
        return res;

    }
};

int main() {
    return 0;
}