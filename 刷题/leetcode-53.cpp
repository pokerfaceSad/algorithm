# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int len = nums.size();
    //     // dp[i]表示以nums[i]结尾的最大子序和
    //     // 递推关系 dp[i] = max(dp[i-1] + nums[i], nums[i])
    //     // 初始值 dp[0] = nums[0]
    //     int dp[len];
    //     dp[0] = nums[0];
    //     int res = dp[0];
    //     for (int i = 1 ; i < len ; i++) {
    //         dp[i] = max(dp[i-1] + nums[i], nums[i]);
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    // dp优化
    // int maxSubArray(vector<int>& nums) {
    //     int len = nums.size();
    //     // dp[i]表示以nums[i]结尾的最大子序和
    //     // 递推关系 dp[i] = max(dp[i-1] + nums[i], nums[i])
    //     // 初始值 dp[0] = nums[0]
    //     int dp;
    //     dp = nums[0];
    //     int res = dp;
    //     for (int i = 1 ; i < len ; i++) {
    //         dp = max(dp + nums[i], nums[i]);
    //         res = max(res, dp);
    //     }
    //     return res;
    // }

    // 分治法
    // 对每一个区间维护四个量
    // 1. lSum 以左端点开始的最大子序和
    // 2. rSum 以右端点开始的最大子序和
    // 3. mSum 整个区间的最大子序和
    // 4. iSum 整个区间的元素和
    struct status
    {
        int lSum;
        int rSum;
        int mSum;
        int iSum;
    };
    
    // pushUp将左子区间和右子区间的status合并成父区间的status
    status pushUp(status lSubStat, status rSubStat) {
        int lSum = max(lSubStat.lSum, lSubStat.iSum + rSubStat.lSum);
        int rSum = max(rSubStat.rSum, rSubStat.iSum + lSubStat.rSum);
        int iSum = lSubStat.iSum + rSubStat.iSum;
        int mSum = max(max(lSubStat.mSum, rSubStat.mSum), lSubStat.rSum + rSubStat.lSum);
        return (status) {lSum, rSum, mSum, iSum};
    }

    status get(vector<int>& nums, int l, int r) {
        if (l == r) {
            // 最小问题 只有一个元素的子区间
            return (status) {nums[l], nums[l], nums[l], nums[l]};
        }
        // 分治处理左子区间和右子区间
        int mid = (l + r) / 2;
        status lSubStat = get(nums, l, mid);
        status rSubStat = get(nums, mid+1, r);
        return pushUp(lSubStat, rSubStat);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main() {

    return 0;
}