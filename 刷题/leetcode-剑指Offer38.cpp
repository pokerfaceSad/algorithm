# include <iostream>
# include <vector>
# include <set>
# include <sstream>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        helper(s, 0, s.size()-1);
        return res;
    }

    void helper(string s, int right, int left) {
        if(right == left) {
            res.push_back(s); return;
        }
        set<int> st;
        for (int i = right ; i <= left; i++) {
            if (st.find(s[i]) != st.end()) continue;
            else st.insert(s[i]);
            swap(s[right], s[i]);
            helper(s, right+1, left);
            swap(s[right], s[i]);
        }
    }
};