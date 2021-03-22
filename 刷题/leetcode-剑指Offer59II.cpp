# include <iostream>
# include <queue>
using namespace std;

class MaxQueue {
public:
    deque<int> dq;
    queue<int> q;
    MaxQueue() {

    }
    
    int max_value() {
        return q.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        if (dq.empty() || value <= dq.back()) dq.push_back(value);
        else {
            while (!dq.empty() && value > dq.back()) dq.pop_back();
            dq.push_back(value);
        }
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int tmp = q.front(); q.pop();
        if (tmp == dq.front()) dq.pop_front();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */