# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right) {
                        left++;
                        if (nums[left] != nums[left-1]) break;
                    }
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    while (left < right) {
                        right--;
                        if (nums[right] != nums[right+1]) break;
                    }
                }
                else {
                    while (left < right) {
                        left++;
                        if (nums[left] != nums[left-1]) break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0,0,0,0};
    auto res = s.threeSum(nums);
    for (auto r : res) {
        for (auto i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}