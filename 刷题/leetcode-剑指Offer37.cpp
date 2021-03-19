# include <iostream>
# include <string>
# include <queue>
# include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return {};
        ostringstream output;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front(); q.pop();
            if (cur) {
                output << cur->val;
                q.push(cur->left);
                q.push(cur->right);
            } else {
                output << '$';
            }
            if (!q.empty()) output << ' ';
        }
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        istringstream input(data);
        string tmp;
        input >> tmp;
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front(); q.pop();

            input >> tmp;
            // tmp = getNextVal(data);
            if (tmp != "$") {
                cur->left = new TreeNode(stoi(tmp));
                q.push(cur->left);
            } else {
                cur->left = NULL;
            }
            input >> tmp;
            // tmp = getNextVal(data);
            if (tmp != "$") {
                cur->right = new TreeNode(stoi(tmp));
                q.push(cur->right);
            } else {
                cur->right = NULL;
            }
        }
        return root;
    } 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    TreeNode* n1 = new TreeNode(798);
    TreeNode* n2 = new TreeNode(80);
    TreeNode* n3 = new TreeNode(2134);
    TreeNode* n4 = new TreeNode(43);
    TreeNode* n5 = new TreeNode(2);
    n1->left = n2; n1->right = n3;
    n3->left = n4; n3->right = n5;
    Codec c;
    string str = c.serialize(n1);
    c.deserialize(str);
    cout << str << endl;
    return 0;
}