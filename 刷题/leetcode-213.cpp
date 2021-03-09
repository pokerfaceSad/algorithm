# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
    }

    int helper(vector<int>& nums, int l, int r) {
        int len = r - l + 1;
        if (len <= 0) return 0;
        if (len == 1) return nums[l];
        int dp0 = nums[l], dp1 = max(nums[l], nums[l+1]), tmp;
        for (int i = 2 ; i < len ; i++) {
            tmp = dp1;
            dp1 = max(dp1, dp0 + nums[l + i]);
            dp0 = tmp;
        }
        return dp1;
    }
};

int main() {
    return 0;
}