# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int res = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
        // push up
        int i = left, j = mid + 1, i_tmp = 0;
        int len = right - left + 1; // 待排序元素和
        while (i_tmp < len) {
            if (i <= mid && (j > right || nums[i] <= nums[j])) {
                tmp[i_tmp] = nums[i];
                i++;
            } else if (j <= right && (i > mid || nums[i] > nums[j])){
                if (i <= mid) res += ((mid - i) + 1);
                tmp[i_tmp] = nums[j];
                j++;
            }
            i_tmp++;
        }
        copy(tmp.begin(), tmp.begin()+len, nums.begin() + left);
        return res;
    }
};

int main() {
    int arr[] = {13,5,4,567,56,73,4,646,5};
    // int arr[] = {3, 2, 1, 0};
    vector<int> data(arr, arr + (sizeof(arr)/sizeof(int)));
    Solution s;
    vector<int> tmp(data.size(), 0);
    s.mergeSort(data, tmp, 0, data.size()-1);
    for (int i : data) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}