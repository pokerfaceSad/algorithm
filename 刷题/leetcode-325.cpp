# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // (x, y) 表示nums[0] + ... + nums[y] 和为 x
        // x重复时 y取较小值
        unordered_map<int, int> hash_map;
        int sum = 0;
        hash_map[0] = -1; // 没有元素相加时和为0
        int res = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
            if (!hash_map.count(sum)) hash_map[sum] = i;
            if (hash_map.count(sum-k)) res = max(res, (i - hash_map[sum-k]));
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,1,0,0};
    Solution s;
    cout << s.maxSubArrayLen(nums, 4) << endl;
    return 0;
}