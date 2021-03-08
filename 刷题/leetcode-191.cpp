# include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n和n-1求与，会消除最后一位的1
        int ans = 0;
        while (n != 0) {
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
};