# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int mid = (high - low) / 2 + low;
        while (low < high) {
            int time = minTime(piles, mid);
            if (time > h) low = mid + 1;
            else high = mid;
            mid = (high - low) / 2 + low;
        }
        return mid;
    }

    int minTime(vector<int>& piles, int speed) {
        int time = 0;
        for (auto pile : piles) {
            time += ( pile + speed - 1 )/ speed;
        }
        return time;
    }
};

int main() {
    vector<int> piles = {30,11,23,4,20};
    Solution s;
    cout << s.minEatingSpeed(piles, 5) << endl;
    return 0;
}