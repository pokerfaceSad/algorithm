# include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        // 从二进制角度考虑 a + b = 无进位和 + 进位
        // 无进位和 = a ^ b
        // 进位 = (a & b) << 1
        return helper(a, b);
    }

    unsigned int helper(unsigned int a, unsigned b) {
        if (b == 0) return a;
        return add(a^b, (a&b)<<1);
    }
};

int main() {
    Solution s;
    unsigned int a;
    a = -2;
    cout << (int)a << endl;
    // cout << s.add(1, 2) << endl;
    return 0;
}