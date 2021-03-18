# include <iostream>
# include <vector>
# include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        if (n == 0) return true;
        stack<int> stk;
        int pop_cur = 0, push_cur = 0;
        while(pop_cur < n) {
            if (!stk.empty() && stk.top() == popped[pop_cur]) {
                stk.pop();
                pop_cur++;
            } else if (push_cur < n) {
                stk.push(pushed[push_cur]);
                push_cur++;
            } else {
                return false;
            }
        }
        return true;

    }
};