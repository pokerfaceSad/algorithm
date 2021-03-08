# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (i == s.size() - 1) {
                res += getValue(s[i]);
                break;
            }
            if (getValue(s[i]) < getValue(s[i+1])) res -= getValue(s[i]);
            else res += getValue(s[i]);
        }
        return res;
    }

    int getValue(char ch) {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return {};
        }
    }
};

int main() {
    return 0;
}