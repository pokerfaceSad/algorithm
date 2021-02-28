# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> table(26, 0);
        for (auto ch : s) {
            table[ch - 'a']++;
        }
        for (auto ch : t) {
            table[ch - 'a']--;
            // 如果两字符串长度相同 则做差后必然有字符的频次小于0
            if (table[ch - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}