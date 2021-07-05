# include <iostream>
# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle = 0;
        while (left < right) {
            middle = left + ((right - left) >> 1);
            if (nums[middle] == target) return middle;
            if (nums[middle] > target) right = middle;
            else left = middle + 1;
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    Solution s;
    cout << s.search(nums, 3) << endl;
    return 0;
}