# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = nums.size() - 2 ;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i >= 0) {
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> v = {1,1};
    Solution s;
    s.nextPermutation(v);
    for (auto num : v) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}