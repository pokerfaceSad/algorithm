# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        for (int index = length-1 ; index >= 0 ; index--) {
            if(digits[index] != 9) {
                digits[index]++;
                return digits;
            } else {
                digits[index] = 0;
                if (index == 0) {
                    vector<int> res;
                    res.push_back(1);
                    res.insert(res.end(), digits.begin(), digits.end());
                    return res;
                }
            }
        }
        return digits;
    }
};

int main() {
    vector<int> v;
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    Solution s;
    vector<int> res = s.plusOne(v);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}