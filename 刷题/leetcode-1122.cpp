# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {    
        unordered_map<int, int> hashmap;
        for (int i = 0 ; i < arr2.size() ; i++) {
            hashmap[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (hashmap.count(x) && !hashmap.count(y)) return true;
            else if (!hashmap.count(x) && hashmap.count(y)) return false;
            else if (!hashmap.count(x) && !hashmap.count(y)) return x < y;
            else return hashmap[x] < hashmap[y];
        });
        return arr1;
    }
};

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    Solution s;
    vector<int> res = s.relativeSortArray(arr1, arr2);
    for (auto num : res) {
        cout << num << endl;
    }
    return 0;
}