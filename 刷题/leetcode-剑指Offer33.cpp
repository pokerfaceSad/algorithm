# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        return helper(postorder, 0, len-1);
        
    }

    bool helper(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int rightSubStart = left;
        while (rightSubStart < right) {
            if (postorder[rightSubStart] < postorder[right]) rightSubStart++;
            else break;
        }
        for (int i = rightSubStart ; i < right ; i++) {
            if (postorder[i] > postorder[right]) continue;
            else return false;
        }
        return helper(postorder, left, rightSubStart-1) && helper(postorder, rightSubStart, right-1);
    }
};

int main() {
    int arr[] = {1,6,3,2,5};
    vector<int> po(arr, arr+5);
    Solution s;
    s.verifyPostorder(po);
    return 0;
}