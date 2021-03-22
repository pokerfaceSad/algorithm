# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     // dp[i] 表示第i个字符结尾的字符串的不重复子串长度
    //     // dp[i] = isExist() ? modify(pos), i - pos: dp[i-1] + 1
    //     // dp[0] = 1;
    //     int len = s.size();
    //     if (len == 0) return 0;
    //     unordered_map<char, int> hash;
    //     vector<int> dp(len, 0);
    //     dp[0] = 1;
    //     int res = dp[0];
    //     hash[s[0]] = 0;
    //     for (int i = 1 ; i < len ; i++) {
    //         if (hash.count(s[i]) && i - dp[i-1] <= hash[s[i]]) {
    //             dp[i] = i - hash[s[i]];
    //             hash[s[i]] = i;
    //         } else {
    //             dp[i] = dp[i-1] + 1;
    //             hash[s[i]] = i;
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;
        unordered_map<char, int> hash;
        int pre = 1;
        int res = pre;
        hash[s[0]] = 0;
        for (int i = 1 ; i < len ; i++) {
            if (hash.count(s[i]) && i - pre <= hash[s[i]]) {
                pre = i - hash[s[i]];
                hash[s[i]] = i;
            } else {
                pre = pre + 1;
                hash[s[i]] = i;
            }
            res = max(res, pre);
        }
        return res;
    }
};

int main() {
    string str = "abba";
    Solution s;
    cout << s.lengthOfLongestSubstring((str)) << endl;
    return 0;
}