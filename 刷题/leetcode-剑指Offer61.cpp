# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 0的个数
        int i = 0;
        for (auto num : nums) {
            if (num == 0) {
                i++;
            } else break;
        }
        int len = nums.size();
        for (int j = i+1 ; j < len ; j++) {
            if (nums[j] - nums[j-1] == 1) continue;
            else if (nums[j] == nums[j-1]) return false;
            else i -= (nums[j] - nums[j-1] - 1);

            if (i < 0) return false;
        }
        return true;

    }
};