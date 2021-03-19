# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int res;
        for (int num : nums) {
            if (vote == 0) res = num;
            num == res ? vote++ : vote--;
        }
        return res;
    }
};