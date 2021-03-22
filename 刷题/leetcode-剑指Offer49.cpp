# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;

        for (int i = 1 ; i < n ; i++) {
            while (dp[a] * 2 <= dp[i-1]) a++;
            while (dp[b] * 3 <= dp[i-1]) b++;
            while (dp[c] * 5 <= dp[i-1]) c++;
            dp[i] = min(dp[a]*2, min(dp[b]*3, dp[c]*5));
        }
        return dp[n-1];
    }
};

int main() {
    return 0;
}