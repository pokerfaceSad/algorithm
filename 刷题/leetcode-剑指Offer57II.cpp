# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 1;
        int sum = 0;
        vector<vector<int>> res;
        while (left <= target/2) {
            sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                vector<int> sub_res;
                for (int i = left ; i <= right; i++) {
                    sub_res.push_back(i);
                }
                res.push_back(sub_res);
                left++;
                right++;
            } else if (sum > target) left++;
            else right++;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.findContinuousSequence(4);
    return 0;
}