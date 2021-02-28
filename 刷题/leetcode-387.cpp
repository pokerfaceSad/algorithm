# include <iostream>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> freq;
        for (char ch : s) {
            ++freq[ch];
        }
        for (int i = 0 ; i < s.size(); i++) {
            if (freq[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}