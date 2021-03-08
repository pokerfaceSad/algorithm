# include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int res = 0;
        while (x != 0) {
            res++;
            x &= (x-1);
        }
        return res;
    }
};