# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        int len = nums.size();
        // 整个数组异或，得到a^b
        for (int num : nums) {
            ret ^= num;
        }
        // 找到a和b相异的一位
        int index = 1;
        while ((ret & index) == 0) {
            index = index<<1;
        }
        int a = 0, b = 0;
        for (int num : nums) {
            // 按照这一位是不是1，将数组分为两组
            if ((num & index) == 0) a ^= num;
            else b ^= num;
        }
        return {a, b};

    }
};