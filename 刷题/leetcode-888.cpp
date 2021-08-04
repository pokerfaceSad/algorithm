# include <iostream>
# include <vector>
# include <numeric>
# include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (aliceSum - bobSum) / 2;
        unordered_set<int> hash_set(aliceSizes.begin(), aliceSizes.end());
        for (int i = 0 ; i < bobSizes.size() ; i++) {
            int target = bobSizes[i] + delta;
            if (hash_set.count(target)) return {target, bobSizes[i]};
        }
        
        return {};
    }
};