# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto num : nums) {
            sum += num;
        }
        return (1 + n) * n / 2 - sum;
    }
};