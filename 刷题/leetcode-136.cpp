# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < len - 1 ; i += 2) {
            if (nums[i] != nums[i+1]) return nums[i];
        }
        return nums[len - 1];

    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    int res = s.singleNumber(nums);
    cout << res <<  endl;

    return 0;
}