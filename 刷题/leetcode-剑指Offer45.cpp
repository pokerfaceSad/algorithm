# include <iostream>
# include <vector>
# include <sstream>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 对数组进行排序
        quickSort(nums, 0, nums.size()-1);
        ostringstream output;
        for (int num : nums) output << to_string(num);
        return output.str();
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int i = l, j = r;
        while (i < j) {
            while (i < j && cmp(nums[l], nums[j])) j--;
            while (i < j && !cmp(nums[l], nums[i])) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }

    // 是否i大于j
    bool cmp(int i, int j) {
        return to_string(i) + to_string(j) < to_string(j) + to_string(i);
    }
};

int main() {
    Solution s;
    int arr[] = {14,2,5,667,53,21,4};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
    s.quickSort(v, 0, v.size()-1);
    for (int i : v) cout << i << " ";
    cout << endl;
    return 0;
}
