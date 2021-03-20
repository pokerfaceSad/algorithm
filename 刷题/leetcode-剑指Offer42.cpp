# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     // dp[i]表示以nums[i]结尾的序列的最大和
    //     // dp[i+1] = max(dp[i] + nums[i+1], nums[i+1])
    //     // dp[0] = nums[0]
    //     int len = nums.size();
    //     vector<int> dp(len, 0);
    //     dp[0] = nums[0];
    //     int res = dp[0];
    //     for (int i = 1 ; i < len ; i++) {
    //         dp[i] = max(dp[i-1] + nums[i], nums[i]);
    //         if (dp[i] > res) res = dp[i];
    //     }
    //     return res;
    // }

    // dp 优化
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0], pre = nums[0];
        for (int i = 1 ; i < len ; i++) {
            pre = max(pre + nums[i], nums[i]);
            if (pre > res) res = pre;
        }
        return res;
    }

    struct status
    {
        int lSum; // 左侧最大子序列和
        int rSum; // 右侧最大子序列和
        int mSum; // 整体最大子序列和
        int iSum; // 所有元素之和
    };

    // 分治
    int maxSubArray(vector<int>& nums) {
        status res = helper(nums, 0, nums.size()-1);
        return res.mSum;
    }

    status helper(vector<int>& nums, int left, int right) {
        if (left == right) return {nums[left], nums[right], nums[left], nums[left]};
        status leftRes = helper(nums, left, (right + left)/2);
        status rightRes = helper(nums, (right + left)/2+1, right);
        // pushUp
        return {
            max(leftRes.iSum + rightRes.lSum, leftRes.lSum),
            max(rightRes.iSum + leftRes.rSum, rightRes.rSum),
            max(leftRes.rSum + rightRes.lSum, max(leftRes.mSum, rightRes.mSum)),
            leftRes.iSum + rightRes.iSum
        };
    }
};

int main() {
    return 0;
}