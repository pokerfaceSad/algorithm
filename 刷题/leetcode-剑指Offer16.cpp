# include <iostream>
using namespace std;

class Solution {
public:
    // 二进制快速幂
    double myPow(double x, int n) {
        if (x == 0) return 0;
        double res = 1;
        long n_ = n;
        if (n < 0) {
            x = 1/x;
            n_ = -n_;
        }
        double pow = x;
        while (n_ != 0) {
            if ( n_ & 1 ) res *= pow;
            pow *= pow;
            n_ >>= 1;
        }
        return res;
    }

    // 递归快速幂
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n < 0) return 1/x * myPow(1/x, -n-1);
        else if (n & 1) return x * myPow(x, n-1);
        else return myPow(x, n/2);
    }
};

int main() {
    return 0;
}