# include <iostream>
# include <vector>
# include <queue>
# include <climits>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = 0, len = nums.size();
        if (len == 0) return {};
        deque<int> dq;
        vector<int> res;
        dq.push_back(nums[0]);
        // 初始化队列
        for (int i = 1 ; i < k ; i++) {
            if (dq.empty() || nums[i] <= dq.back()) dq.push_back(nums[i]);
            else {
                while (!dq.empty() && (nums[i] > dq.back())) dq.pop_back();
                dq.push_back(nums[i]);
            }
            right++;
        }
        res.push_back(dq.front());
        // 滑动窗口
        while (right != len - 1) {
            if (nums[left] == dq.front()) dq.pop_front();
            left++;
            right++;
            if (dq.empty() || nums[right] <= dq.back()) dq.push_back(nums[right]);
            else {
                while (!dq.empty() && (nums[right] > dq.back())) dq.pop_back();
                dq.push_back(nums[right]);
            }
            res.push_back(dq.front());
            if (right == len-1) return res;
        }
        return res;
    }
}; 

int main() {
    Solution s;
    int arr[] = {1,3,-1,-3,5,3,6,7};
    vector<int> data(arr, arr + (sizeof(arr)/sizeof(int)));
    s.maxSlidingWindow(data, 3);
    return 0;
}