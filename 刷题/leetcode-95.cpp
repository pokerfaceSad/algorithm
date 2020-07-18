# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) {
            vector<TreeNode*> headList;
            headList.push_back(NULL);
            return headList;
        }

        vector<TreeNode*> headList;
        for (int i = start ; i <= end ; i++) {

            vector<TreeNode*> leftSubTree = generate(start, i-1);
            vector<TreeNode*> rightSubTree = generate(i+1, end);

            for (int j = 0 ; j < leftSubTree.size(); j++) {
                for (int k = 0 ; k < rightSubTree.size(); k++) {
                    TreeNode *head = new TreeNode(i);
                    head->left = leftSubTree[j];
                    head->right = rightSubTree[k];
                    headList.push_back(head);
                }
            }
        }
        return headList;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        vector<TreeNode*> ret = generate(1, n);
        return ret;
    }
};

void bfs(TreeNode* head, vector<int> &output) {
    queue<TreeNode*> q;
    q.push(head);
    output.clear();
    TreeNode *node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if(node == NULL) {
            output.push_back(NULL);
            continue;
        } else {
            output.push_back(node->val);
        }
        
        if(node->left != NULL) q.push(node->left);
        else q.push(NULL);
        if(node->right != NULL) q.push(node->right);
        else q.push(NULL);
    } 
}


int main() {
    Solution s;
    vector<TreeNode*> ret = s.generateTrees(3);
    for (int i=0 ; i < ret.size() ; i++) {
        vector<int> output;
        bfs(ret[i], output);
        for(vector<int>::iterator it = output.begin();it != output.end();it++) {
            if(*it != NULL)
                cout << *it <<" ";
            else
                cout << "NULL ";
        }
        cout << "\n";
            
    }
    return 0;
}