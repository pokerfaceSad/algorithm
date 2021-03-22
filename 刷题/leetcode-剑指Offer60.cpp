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
        // dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1, .... , dp[1][6] = 1
        vector<vector<int>> dp(n+1, vector<int>(6*n+1, 0));
        for (int i = 1 ; i <= 6 ; i++) dp[1][i] = 1;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= 6*i ; j++) {
                if (j < i) {
                    dp[i][j] = 0;
                    continue;
                }
                for (int k = 1 ; k <= 6 && j-k > 0 ; k++) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        int total = pow(6, n);
        vector<double> res;
        for (double num : dp[n]) {
            if (num == 0) continue;
            res.push_back(num/total);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<double> res = s.dicesProbability(1);
    for (auto num : res) {
        cout << num << " " << endl;
    }


    return 0;
}