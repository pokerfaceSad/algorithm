# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        int len = nums.size();
        for (int index = 0 ; index < len ; index++) {
            auto it = hashtable.find(target - nums[index]);
            if(it != hashtable.end()) {
                return {it->second, index};
            }
            hashtable[nums[index]] = index;
        }
        return {};
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    Solution s;
    vector<int> res = s.twoSum(v, 5);
    for(auto i : res) {
        cout << i << endl;
    }
    return 0;
}