# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int numsSize = nums.size();
        sort(nums.begin(), nums.end());
        int rst = 0;
        for(int i = 0 ; i < numsSize ; i+=2) {
            rst += nums[i];
        }
        return rst;
    }
};

int main() {

    vector<int> nums = {1,2,3,4};
    Solution s;
    int rst = s.arrayPairSum(nums);
    cout << rst << endl;
    return 0;
}