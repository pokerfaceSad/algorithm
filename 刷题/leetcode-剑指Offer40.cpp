# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int, vector<int>, less<int>> q; // 大顶堆
        for (int i = 0 ; i < k; i++) {
            q.push(arr[i]);
        }
        int size = arr.size();
        for (int i = k ; i < size ; i++) {
            if (q.top() > arr[i]) {
                q.pop(); q.push(arr[i]);
            }
        }
        vector<int> res(k, 0);
        for (int i = 0 ; i < k ; i++) {
            res[i] = q.top(); q.pop();
        }
        return res;
    }
};

int main() {
    priority_queue<int, vector<int>, less<int>> q; 
    q.push(1);
    q.push(7);
    q.push(5);
    q.push(8);
    q.push(3);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}