# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int deleteNum = 0;
        int slow = 0;
        for (int fast = 0 ; fast < len ; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            } else {
                deleteNum++;
            }
        }
        return len - deleteNum;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution s;
    int len = s.removeElement(nums, 1);
    for (int i = 0 ; i < len; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}