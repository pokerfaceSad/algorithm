# include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int slow = 0;
        int maxLength = 0;
        int fast = 0;
        for ( ; fast < len ; fast++) {
            if (nums[fast] != 1) {
                maxLength =  fast - slow > maxLength ? fast - slow : maxLength;
                slow = fast + 1;
            }
        }
        maxLength =  fast - slow > maxLength ? fast - slow : maxLength;
        return maxLength;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    Solution s;
    int maxLength = s.findMaxConsecutiveOnes(nums);
    cout << maxLength << endl;
    return 0;
}