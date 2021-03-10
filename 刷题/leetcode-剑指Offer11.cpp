# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size()-1;
        int mid = low + (high - low) / 2;
        while (low < high) {
            if (numbers[high] > numbers[mid]) {
                high = mid;
            } else if (numbers[high] < numbers[mid]) {
                low = mid + 1;
            } else {
                high--;
            }
            mid = low + (high - low) / 2;
        }
        return numbers[low];
    }
};

int main() {
    int arr[] = {3,1};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    Solution s;
    s.minArray(nums);
    return 0;
}