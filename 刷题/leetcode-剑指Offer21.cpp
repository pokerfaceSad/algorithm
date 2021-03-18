# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int front = 0, tail = nums.size() - 1;
        while (front < tail) {
            while (front < tail && (nums[front] & 1) != 0) front++;
            while (front < tail && (nums[tail] & 1) != 1) tail--;
            if (front > tail) return nums;
            swap(nums[front], nums[tail]);
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    s.exchange(nums);
    return 0;
}