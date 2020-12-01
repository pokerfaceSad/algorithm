# include <string>
# include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int slow = 0;
        for (int fast = 0 ; fast < len ; fast++) {
            if (s[fast] == ' ') {
                int right = slow, left = fast - 1;
                while (right < left) {
                    swap(s[right], s[left]);
                    right++;
                    left--;
                }
                slow = fast + 1;
            }
        }
        int right = slow, left = len - 1;
        while (right < left) {
            swap(s[right], s[left]);
            right++;
            left--;
        }
        return s;
    }
};

int main() {
    string str = "123 456 78910";
    Solution s;
    cout << s.reverseWords(str) << endl;
    return 0;
}