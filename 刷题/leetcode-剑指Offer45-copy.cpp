#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        ostringstream oss;
        for (auto num : nums) oss << to_string(num);
        return oss.str();
    }

    void quickSort(vector<int>& nums, int left, int right) {        
        if (left >= right) return;

        int i = left, j = right;
        while(i < j) {
            // while (i < j && nums[j] > nums[left]) j--;
            // while (i < j && nums[i] <= nums[left]) i++;
            while (i < j && cmp(nums[j], nums[left])) j--;
            while (i < j && !cmp(nums[i], nums[left])) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        quickSort(nums, left, i-1);
        quickSort(nums, i+1, right);
    }

    bool cmp(int num1, int num2) {
        return to_string(num1) + to_string(num2) < to_string(num2) + to_string(num1);
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(5);
    Solution s;
    s.quickSort(nums, 0, nums.size()-1);
    for (auto num : nums) {
        cout << num << endl;
    }
    return 0;
}