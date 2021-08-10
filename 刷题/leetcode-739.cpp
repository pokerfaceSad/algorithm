# include <iostream>
# include <vector>
# include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0 ; i < temperatures.size() ; i++) {
            if (stk.empty() || temperatures[i] <= stk.top().second) {
                stk.push({i, temperatures[i]});
            } else {
                while (!stk.empty() && temperatures[i] > stk.top().second) {
                    res[stk.top().first] = i - stk.top().first;
                    stk.pop();
                }
                stk.push({i, temperatures[i]});
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> tempers = {73,74,75,71,69,72,76,73};
    auto res = s.dailyTemperatures(tempers);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}