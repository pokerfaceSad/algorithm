# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int slow = 0;
        int sum = 0;
        int minLength = len;
        for (int fast = 0 ; fast < len ; fast++) {
            sum += nums[fast];
            if (sum >= s) {
                while (slow <= fast) {
                    if (sum - nums[slow] >= s) {
                        if (slow == fast) return 1;
                        sum -= nums[slow];
                        slow++;
                    } else {
                        minLength = fast - slow + 1 < minLength ? fast - slow + 1 : minLength;
                        break;
                    }
                }
            }
        }
        return sum >= s ? minLength : 0;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(10);
    Solution s;
    int minLength = s.minSubArrayLen(100, nums);
    cout << minLength << endl;
    return 0;
}