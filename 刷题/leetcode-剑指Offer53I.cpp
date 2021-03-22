# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int index = my_search(nums, 0, len-1, target);
        if (index == -1) return 0;
        int i = index-1, j = index+1;
        int res = 1;
        while (i >= 0 && nums[i--] == target) res++;
        while (j < len && nums[j++] == target) res++;
        return res;
    }

    int my_search(vector<int>& nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (left == right) return -1;
        else if (nums[mid] > target) return my_search(nums, left, mid, target);
        else return my_search(nums, mid + 1, right, target);
    }
};

int main() {
    int arr[] = {1,6,7,7,8};
    vector<int> data(arr, arr + (sizeof(arr) / sizeof(int)));
    Solution s;
    cout << s.my_search(data, 0, data.size(), 7) << endl;
    return 0;
}