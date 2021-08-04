# include <iostream>
# include <vector>
# include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};


ostringstream oss;
vector<int> res;
vector<int> vals;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        int ret = 0;
        for (auto num : res) {
            ret += num;
        }
        res.clear();
        vals.clear();
        return ret;
    }

    void dfs(TreeNode* root) {
        if (root != nullptr) {
            vals.push_back(root->val);
        }
        if (root->left == nullptr && root->right == nullptr) {
            ostringstream oss;
            for (auto val : vals) {
                oss << val;
            }
            res.push_back(std::stoi(oss.str()));
            return;
        }
        if (root->left != nullptr) {
            dfs(root->left);
            vals.pop_back();
        }
        if (root->right != nullptr) {
            dfs(root->right);
            vals.pop_back();
        }
    }
};

int main() {
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(0);
    TreeNode* n4 = new TreeNode(5);
    TreeNode* n5 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    Solution s;
    cout << s.sumNumbers(n1) << endl;
    
}