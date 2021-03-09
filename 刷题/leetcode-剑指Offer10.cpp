# include <iostream>
# include <vector>
using namespace std;

/**
 * 注意循环求余  (x + y) % p = (x % p + y % p) % p
 */ 
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int prepre = 0, pre = 1, tmp;
        for (int i = 2 ; i <= n ; i++) {
            tmp = pre;
            pre = (prepre + pre) % 1000000007;
            prepre = tmp;
        }
        return int(pre % 1000000007);
    }
};

int main() {
    return 0;
}