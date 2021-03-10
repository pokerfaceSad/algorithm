# include <iostream>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        // dp[i] 为爬到第i阶的方法数
        // dp[i] = dp[i-1] + dp[i-2]
        // dp0 = 1 dp1 = 1 dp2 = 2
        int prepre = 1, pre = 1, tmp;
        for (int i = 2 ; i <= n; i++) {
            tmp = pre;
            pre = (pre + prepre) % 1000000007;
            prepre = tmp;
        }
        return pre;
    }
};

int main() {
    return 0;
}