# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int index1 = 0, index2 = 0;
        int length1 = nums1.size(), length2 = nums2.size();
        while (index1 < length1 && index2 < length2) {
            if (nums1[index1] == nums2[index2]) {
                result.push_back(nums1[index1]);
                index1++;
                index2++;
                continue;
            }
            if (nums1[index1] > nums2[index2]) {
                index2++;
            } else {
                index1++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v2.push_back(5);
    Solution s;
    vector<int> res = s.intersect(v1, v2);
    for (int a : res) {
        cout << a << endl;
    }
    return 0;
}