# include <iostream>
# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    // 也可以使用 leftPart * 2 + nums[i] = sum(nums)来判断
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int leftPart = 0;
        int rightPart = accumulate(nums.begin(), nums.end(), -nums[0]);
        if (leftPart == rightPart) return 0;
        for (int i = 1 ; i < nums.size(); i++) {
            leftPart = leftPart + nums[i-1];
            rightPart = rightPart - nums[i];
            if (leftPart == rightPart) return i;
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
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    cout << s.pivotIndex(nums) << endl;
    return 0;
}