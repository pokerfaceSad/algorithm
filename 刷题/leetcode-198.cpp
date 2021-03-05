# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        // dp[i]表示前n项组成的数组的解
        // 递推关系 dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        // 初始值 dp[0] = nums[0] dp[1] = max(nums[0], nums[1])
        if (len == 0) return 0;
        else if (len == 1) return nums[0];
        int dp[len];
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (int i = 2 ; i < len ; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[len-1];
    }
};

int main() {
    return 0;
}