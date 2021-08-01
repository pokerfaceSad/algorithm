# include <iostream>
# include <vector>
# include <stack>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if (num.size() == 0) return {k};
        stack<int> stk;
        int curNum = 0;
        int pushUp = 0;
        int index = 0;
        for (index = num.size() - 1 ; index >= 0 && k != 0 ; index--) {
            curNum = k % 10;
            k = k / 10;
            stk.push((num[index] + curNum + pushUp) % 10);
            pushUp = (num[index] + curNum + pushUp > 9) ? 1 : 0;
        }
        if (k != 0) {
            // TODO
            while (k != 0) {
                curNum = k % 10;
                k = k/10;
                stk.push((curNum + pushUp) % 10);
                pushUp = (curNum + pushUp) > 9 ? 1 : 0;
            }
        }
        if (index >= 0) {
            for ( ;index >= 0 ; index--) {
                stk.push((num[index] + pushUp) % 10);
                pushUp = (num[index] + pushUp > 9) ? 1 : 0;
            }
        }
        if (pushUp == 1) stk.push(1);

        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;

    }

};

int main() {
    vector<int> num = {0};
    int k = 23;
    Solution s;
    vector<int> res = s.addToArrayForm(num, k);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    
}