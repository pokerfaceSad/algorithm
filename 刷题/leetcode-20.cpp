# include <iostream>
# include <string>
# include <stack>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        stack<char> stk;
        for (char ch : s) {
            if (pairs.count(ch)) {
                if (!stk.empty() && stk.top() == pairs[ch]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(ch);
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
};

int main() {
    return 0;
}