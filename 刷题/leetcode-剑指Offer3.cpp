# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    // hash表遍历
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto num : nums) {
            if (!hashset.count(num)) {
                hashset.insert(num);
            } else {
                return num;
            }
        }
        return {};
    }

    // 原地置换
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0 ; i < nums.size() ; i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                } else {
                    swap(nums[nums[i]], nums[i]);
                }
            }
        }
        return {};
    }

};

int main() {
    int arr[] = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
    cout << v.size() << endl;
    Solution s;
    cout << s.findRepeatNumber(v) << endl;
    return 0;
}