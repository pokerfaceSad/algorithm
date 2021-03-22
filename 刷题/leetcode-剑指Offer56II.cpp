# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> counts(32, 0);
        for (int num : nums) {
            for (int i = 0 ; i < 32 ; i++) {
                if (num & 1) counts[i]++;
                num >>= 1;
            }
        }
        for (int i = 0 ; i < 32 ; i++) counts[i] %= 3;
        int res = 0;
        for (int i = 0 ; i < 32 ; i++) {
            if (counts[i] == 1) res = res | (1 << i);
        }
        return res;
    }
};