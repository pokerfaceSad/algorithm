# include <iostream>
# include <vector>
using namespace std;

// 可以使用二分查找 速度更快
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for (auto p : nums) {
            if (p > target || p == target) return index;
            else index++;
        }
        return index;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution s;
    cout << s.searchInsert(nums, 3) << endl;
    return 0;
}