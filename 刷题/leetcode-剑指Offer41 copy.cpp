# include <iostream>
# include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> big_head;
    priority_queue<int, vector<int>, greater<int>> small_head;

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(big_head.size() == small_head.size()) {
            big_head.push(num);
            small_head.push(big_head.top());
            big_head.pop();
        } else {
            small_head.push(num);
            big_head.push(small_head.top());
            small_head.pop();
        }
    }
    
    double findMedian() {
        if (big_head.size() == small_head.size()) return ((double)big_head.top() + (double)small_head.top())/2;
        else return (double)small_head.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */