# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int slow = 0;
        for (int fast = 0 ; fast < len ; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    Solution s;
    int len = s.removeDuplicates(nums);
    cout << len << endl; 
    for (int i = 0 ; i < len ; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}