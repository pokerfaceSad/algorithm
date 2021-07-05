# include <iostream>
# include <vector>
# include <cmath>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hashtable;
        int left = 0, right = 0, len = fruits.size(), ret = 0;
        for (;right < len ; right++) {
            if (hashtable.count(fruits[right]) == 0) {
                hashtable[fruits[right]] = 1;
            } else hashtable[fruits[right]]++;
            
            while (hashtable.size() > 2) {
                if (--hashtable[fruits[left]] == 0) hashtable.erase(fruits[left]);
                left++;
            }
            ret = (right - left + 1) > ret ? (right - left + 1) : ret;
        }
        return ret;
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    Solution s;
    cout << s.totalFruit(v) << endl;

    return 0;
}