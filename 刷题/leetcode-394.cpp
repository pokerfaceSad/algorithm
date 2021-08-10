# include <iostream>
# include <string>
# include <stack>
# include <vector>
# include <sstream>
# include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        size_t p = 0;
        ostringstream oss;
        while (p < s.size()) {
            if (isdigit(s[p])) {
                while (isdigit(s[p])) oss << s[p++];
                stk.push(oss.str());
                oss.str("");
            } else if (s[p] == '[') {
                stk.push(string(1, s[p++]));
            } else if (isalpha(s[p])) {
                while (isalpha(s[p])) oss << s[p++];
                stk.push(oss.str());
                oss.str("");
            } else {
                vector<string> substrs;
                while (stk.top().compare("[") != 0) {
                    substrs.push_back(stk.top()); stk.pop();
                }
                stk.pop(); // pop [
                reverse(substrs.begin(), substrs.end());
                for (auto str : substrs) oss << str;
                string substr = oss.str(); oss.str("");
                for (int i = atoi(stk.top().c_str()) ; i > 0 ; i--) {
                    oss << substr;
                }
                stk.pop();
                stk.push(oss.str()); oss.str("");
                p++;
            }
        }
        vector<string> substrs;
        while (!stk.empty()) {
            substrs.push_back(stk.top()); stk.pop();
        }
        reverse(substrs.begin(), substrs.end());
        for (auto str : substrs) oss << str;
        return oss.str();
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[ab2[e]c]") << endl;
    return 0;
}