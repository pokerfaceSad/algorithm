# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] == mid) left = mid+1;
            else right = mid;
            mid = (left + right) / 2;
        }
        return left;
    }
};