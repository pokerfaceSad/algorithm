# include <iostream>
# include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while ( x != 0 ) {
            int end = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && end > INT_MAX % 10)) 
                return 0;
            if (res < INT_MIN/10 || (res == INT_MIN/10 && end < INT_MIN % 10))
                return 0;
            res = res * 10 + end;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverse(-123) << endl;
    return 0;
}