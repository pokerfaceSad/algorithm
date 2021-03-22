# include <iostream>
# include <algorithm>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.end() - n, s.end());
        reverse(s.begin(), s.end() - n);
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseLeftWords("lrloseumgh", 6) << endl;
    return 0;
}