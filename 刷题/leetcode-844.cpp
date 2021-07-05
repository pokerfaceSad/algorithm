# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int index_s = s.length()-1, index_t = t.length()-1;
        int skip_s = 0, skip_t = 0;
        while (index_s >= 0 || index_t >= 0) {
            while (index_s >= 0) {
                if (s[index_s] == '#') {
                    skip_s++;
                    index_s--;
                } else if (skip_s > 0) {
                    skip_s--;
                    index_s--;
                } else break;
            }
            while (index_t >= 0) {
                if (t[index_t] == '#') {
                    skip_t++;
                    index_t--;
                } else if (skip_t > 0) {
                    skip_t--;
                    index_t--;
                } else break;
            }
            if (index_s >= 0 || index_t >= 0) {
                if (index_s >= 0 && index_t >= 0) {
                    if (s[index_s] == t[index_t]) {
                        index_s--;
                        index_t--;
                    } else return false;
                } else return false;
            } else return true;
        }
        return true;
    }
};

int main() {
    string s = "c";
    string t = "d#c";
    // string s = "xywrrmp";
    // string t = "xywrrmu#p";
    Solution sol;
    cout << sol.backspaceCompare(s, t) << endl;
    return 0;
}