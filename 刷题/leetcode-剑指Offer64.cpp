# include <iostream>
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        int res = 0;
        n && (res = n + sumNums(n-1));
        return res;
    }
};