# include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int slow = 0;
        for (int fast = 0 ; fast < len ; fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    Solution s;
    s.moveZeroes(nums);
    for (auto p:nums) {
        cout << p << endl;
    }
    return 0;
}