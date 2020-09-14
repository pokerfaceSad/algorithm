# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0, index2 = numbers.size() - 1;
        while(true) {
            int sum = numbers[index1] + numbers[index2];
            if (sum == target) {
                return {index1 + 1, index2 + 1};
            } else if (sum > target) {
                index2--;
            } else if (sum < target) {
                index1++;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    Solution s;
    vector<int> rst = s.twoSum(numbers, 5);
    cout << rst[0] << endl;
    cout << rst[1] << endl;
    return 0;
}