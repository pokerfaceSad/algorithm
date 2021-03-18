# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = pow(10, n) - 1;
        vector<int> res(max, 0);
        for (int i = 0 ; i < max ; i++) {
            res[i] = i+1;
        }
        return res;
    }
};

int main() {
    return 0;
}