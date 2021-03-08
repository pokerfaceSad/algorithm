# include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int next1 = 1,next2 = 1, tmp;
        for (int i = 2 ; i < n+1 ; i++) {
            tmp = next1 + next2;
            next2 = next1;
            next1 = tmp;
        }
        return tmp;

    }
};

int main() {

    return 0;
}