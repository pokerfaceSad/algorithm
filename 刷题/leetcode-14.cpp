# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return {};
        if (strs.size() == 1) return strs[0];
        string commonPrefix = "";
        int index = 0;
        int strNum = strs.size();
        char ch;
        while(true) {
            if (strs[0].size() < index) return commonPrefix;
            ch = strs[0][index];
            for (size_t i = 1 ; i < strs.size() ; i++) {
                if (strs[i].size() < index) return commonPrefix;
                else if (strs[i][index] == ch) {
                    if (i == strNum - 1) commonPrefix+=ch;
                    else continue;
                } else {
                    return commonPrefix;
                }
            }
            index++;
        }
        
    }
};

int main() {
    vector<string> strs;
    // strs.push_back("123");
    // strs.push_back("1234");
    // strs.push_back("12345");
    Solution s;
    string str = s.longestCommonPrefix(strs);
    cout << str << endl;
    return 0;
}