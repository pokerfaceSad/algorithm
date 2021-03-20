# include <iostream>
# include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> small_head;
    priority_queue<int, vector<int>, less<int>> big_head;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (small_head.size() == big_head.size()) {
            small_head.push(num);
            big_head.push(small_head.top());
            small_head.pop();
        } else {
            big_head.push(num);
            small_head.push(big_head.top());
            big_head.pop();
        }
    }
    
    double findMedian() {
        if (small_head.size() == big_head.size()) return ((double)(small_head.top() + big_head.top()))/2;
        else return big_head.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    return 0;
}