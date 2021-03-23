# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> b_up(len , 1);
        vector<int> b_down(len, 1);
        // 计算下三角
        for (int i = 1 ; i < len ; i++) {
            b_down[i] = b_down[i-1] * a[i-1];
        }
        // 计算上三角
        for (int i = len-2 ; i >= 0 ; i--) {
            b_up[i] = b_up[i+1] * a[i+1];
        }

        for (int i = 0 ; i < len ; i++) {
            b_up[i] *= b_down[i];
        }
        return b_up;
    }
};

int main() {
    Solution s;
    int arr[] = {1,2,3,4,5};
    vector<int> a(arr, arr + (sizeof(arr)/sizeof(int)));
    vector<int> res = s.constructArr(a);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}