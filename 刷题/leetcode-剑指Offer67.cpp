# include <iostream>
# include <climits>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        // 去除空格
        int len = str.size();
        if (len == 0) return 0;
        int index = 0;
        while (str[index] == ' ') index++;
        // 判断正负
        bool isNeg = false;
        if (str[index] == '+') {
            isNeg = false;
            index++;
        } else if (str[index] == '-') {
            isNeg = true;
            index++;
        }
        // 找出所有数字
        int end = index;
        while(end < len && str[end] >= '0' && str[end] <= '9') end++;
        if (end == index) return 0;
        // 合成结果
        int res = 0;
        for (int i = index ; i < end ; i++) {
            if (isNeg) {
                if (res < INT_MIN/10 || (res == INT_MIN/10 && -(str[i] - '0') < INT_MIN%10)) return INT_MIN;
                else res = res * 10 - (str[i] - '0');
            } else {
                if (res > INT_MAX/10 || (res == INT_MAX/10 && (str[i] - '0') > INT_MAX%10)) return INT_MAX;
                else res = res * 10 + (str[i] - '0');
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.strToInt("2147483648") << endl;
    return 0;
}