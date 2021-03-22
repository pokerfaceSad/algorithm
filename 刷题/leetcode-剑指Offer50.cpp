# include <iostream>
# include <unordered_map>
# include <queue>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        int len = s.size();
        unordered_map<char, bool> hash;
        queue<char> q;
        for (int i = 0 ; i < len ; i++) {
            if (!hash.count(s[i])) {
                hash[s[i]] = true;
                q.push(s[i]);
            } else {
                hash[s[i]] = false;
                while (!q.empty() && !hash[q.front()]) q.pop();
            }
        }
        return q.empty() ? ' ' : q.front();
    }
};

int main() {
    return 0;
}
