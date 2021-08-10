# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int slow = 0;
        for (int fast = 0 ; fast < s.size() ; fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                int start = slow;
                while (fast < s.size() && s[fast] != ' ') s[slow++] = s[fast++];
                reverse(s.begin() + start, s.begin() + slow);
            }
        }
        s.erase(s.begin() + slow, s.end());
        return s;
    }
};

int main() {
    Solution s;
    string str = s.reverseWords("abc def  ");
    cout << str << endl;
    return 0;
}