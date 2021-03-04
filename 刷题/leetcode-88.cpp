# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    // 双指针从后向前填充nums1
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        for (int i = m+n-1 ; i >= 0 ; i--) {
            if (p1 < 0) {
                nums1[i] = nums2[p2];
                p2--;
                continue;
            } else if (p2 < 0) {
                // nums1剩下的部分是有序的 无需继续处理
                return;
            }
            if (nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
        }
    }
};

int main() {
    int a1[] = {1,2,3,0,0,0};
    int a2[] = {2,5,6};
    int m = 3, n = 3;
    vector<int> v1(a1, a1 + 6);
    vector<int> v2(a2, a2 + 3);
    Solution s;
    s.merge(v1, m, v2, n);
    for (auto i : v1) {
        cout << i << endl;
    }
    return 0;
}