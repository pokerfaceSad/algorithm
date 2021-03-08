# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        data.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = data.size();
        vector<int> shuffled(data.begin(), data.end());
        for (int i = 0 ; i < len ; i++) {
            swap(shuffled[i], shuffled[rand() % (len - i) + i]);
        }
        return shuffled;
    }
private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    cout << rand() << endl;
    return 0;
}