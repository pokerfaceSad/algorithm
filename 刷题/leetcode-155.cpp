# include <iostream>
# include <stack>
# include <climits>
using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        min.push(std::min(x, min.top()));
    }
    
    void pop() {
        stk.pop();
        min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */