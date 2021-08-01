# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        for (int i = 0 ; i <= len - 2 ; i++) {
            if (nums[i] > nums[i+1]) {
                count++;
                if (count > 1) return false;
                else {
                    if (i > 0 && nums[i+1] < nums[i-1]) nums[i+1] = nums[i];
                    else nums[i] = nums[i+1];
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> v = {1, -1, -2, 4};
    Solution s;
    cout << s.checkPossibility(v) << endl;
    return 0;
}