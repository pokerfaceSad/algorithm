# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int low = 0, high = *max_element(arr.begin(), arr.end());
        vector<int> prefix(arr.size() + 1, 0); // prefix[i]表示前i个元素的和
        for (int i = 0 ; i < arr.size() ; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }
        int ans;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            int index = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int sum = prefix[index] + (arr.size() - index) * mid;
            if (sum >= target) {
                high = mid;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return abs(check(arr, ans) - target) > abs(check(arr, ans + 1) - target) ? ans + 1 : ans;
        
    }

    int check(vector<int>& arr, int value) {
        int sum = 0;
        for (auto val : arr) {
            sum += (val > value ? value : val);
        }
        return sum;
    }
};

int main() {
    vector<int> arr = {2, 3, 5};
    Solution s;
    cout << s.findBestValue(arr, 10) << endl;
    return 0;
}