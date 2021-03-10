# include <iostream>
# include <stack>
using namespace std;

/**
 * 两个栈，一个负责进，一个负责出
 * 当需要弹出且输出栈为空时，才将输入栈的元素全部倒进输出栈
 * 倒的过程会将元素顺序逆置，这样在弹出的过程中就能够符合队列先进先出的规则
 */
class CQueue {
private:
    stack<int> stk_in;
    stack<int> stk_out;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stk_in.push(value);
    }
    
    int deleteHead() {
        int tmp;
        if (stk_out.empty()) {
            if (stk_in.empty()) return -1;
            else {
                while (!stk_in.empty()) {
                    stk_out.push(stk_in.top());
                    stk_in.pop();
                }
            }
        }
        tmp = stk_out.top();
        stk_out.pop();
        return tmp;
    }
};

int main() {
    return 0;
}
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */