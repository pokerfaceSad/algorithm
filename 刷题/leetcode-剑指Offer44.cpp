# include <iostream>
# include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n<10) return n;
        long no = n;
        no++;
        long long len = 10;
        long long cur_num = 90;
        int e = 1;
        while (len < no) {
            len += cur_num * (++e);
            cur_num = cur_num * 10;
        }
        int index = ceil((no - (len - cur_num/10 * e))/(double)e);
        int dig_index = (e - (no - (len - cur_num/10 * e))%e)%e + 1;
        int num = pow(10, e-1) + index - 1;
        return int(num/pow(10, dig_index-1)) %10;;


    }
};

int main() {
    Solution s;
    for (int i = 300 ; i < 400; i++)
        cout << s.findNthDigit(i);

    return 0;
}