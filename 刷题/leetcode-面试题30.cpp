# include <iostream>
# include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> minStk;
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || minStk.top() >= x) minStk.push(x);
    }
    
    void pop() {
        if (stk.empty()) return;
        int tmp = stk.top(); stk.pop();
        if (tmp == minStk.top()) minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */