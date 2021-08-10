# include <iostream>
# include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        while (s[idx] == ' ') idx++;
        bool isNeg = false;
        if (s[idx] == '-') {
            isNeg = true; idx++;
        } else if (s[idx] == '+') {
            isNeg = false;
            idx++;
        }
        int res = 0;
        while (isdigit(s[idx])) {
            if (isNeg) {
                res = (res < INT_MIN / 10 || (res == INT_MIN / 10 && (-(s[idx] - '0') < INT_MIN % 10))) ? INT_MIN : res * 10 - (s[idx] - '0');
            } else {
                res = (res > INT_MAX / 10) || (res == INT_MAX / 10 && ((s[idx] - '0') > INT_MAX % 10)) ? INT_MAX : res * 10 + (s[idx] - '0');
            }
            idx++;
        }
        return res;
    }
};

int main() {
    return 0;
}