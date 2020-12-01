# include <vector>
# include <iostream>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right];
        
    }
};

int main() {
    vector<int> nums;
    nums.push_back(4);
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}