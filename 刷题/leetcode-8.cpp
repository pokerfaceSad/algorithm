# include <iostream>
# include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false;
        int index = 0;
        // 处理前面的空格
        while (s[index] == ' ') index++;
        // 如果以非数字字符开头直接返回0
        if (s[index] == '-'){
            isNegative = true;
            index++;
        } else if (s[index] == '+') {
            isNegative = false;
            index++;
        }
        if (!(s[index] >= '0' && s[index] <= '9')) return 0;
        int res = 0;
        int current = 0;
        while (index < s.size()) {
            if (!(s[index] >= '0' && s[index] <= '9')) return res;
            if (isNegative) current = -(s[index] - '0');
            else current = (s[index] - '0');
            if (res > INT_MAX/10 || (res == INT_MAX/10 && current > INT_MAX % 10)) return INT_MAX;
            if (res < INT_MIN/10 || (res == INT_MIN/10 && current < INT_MIN % 10)) return INT_MIN;
            res = res * 10 + current;
            index++;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("123456") << endl;
    return 0;
}