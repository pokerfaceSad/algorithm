# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int min = 0;
        int len = nums.size();
        if (len == 0) return {};
        while (min+1 < len && (abs(nums[min]) >= abs(nums[min+1]))) min++;
        int pos = min-1, neg = min+1;
        ans.push_back(nums[min]*nums[min]);
        while (pos >= 0 && neg < len) {
            if (abs(nums[pos]) > abs(nums[neg])) {
                ans.push_back(nums[neg] * nums[neg]);
                neg++;
            } else {
                ans.push_back(nums[pos]*nums[pos]);
                pos--;
            }
        }
        if (pos >= 0) {
            while (pos >= 0) {
                ans.push_back(nums[pos]*nums[pos]);
                pos--;
            }
        } else if (neg < len) {
            while (neg < len) {
                ans.push_back(nums[neg]*nums[neg]);
                neg++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v;
    v.push_back(-4);
    v.push_back(-4);
    v.push_back(-3);
    // v.push_back(6);
    Solution s;
    vector<int> ret = s.sortedSquares(v);
    for (int i = 0 ; i < ret.size() ; i++){
        cout << ret[i] << endl;
    }
    return 0;
}