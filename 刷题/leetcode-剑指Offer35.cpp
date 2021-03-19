# include <iostream>
# include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        Node* cur, * res = head;
        while(head != NULL) {
            // 复制本身
            if (!hash.count(head)) {
                cur = new Node(head->val);
                hash[head] = cur;
            }
            // 复制next
            if (head->next != NULL) { 
                if (!hash.count(head->next)) {
                    cur = new Node(head->next->val);
                    hash[head->next] = cur;
                } else {
                    cur = hash[head->next]; 
                }
                hash[head]->next = cur;
            }
            // 复制random
            if (head->random != NULL) {
                if (!hash.count(head->random)) {
                    cur = new Node(head->random->val);
                    hash[head->random] = cur;
                } else {
                    cur = hash[head->random];
                }
                hash[head]->random = cur;
            }
            head = head->next;
        }
        return hash[res];
    }
};

int main() {
    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n0->next = n1;
    n1->next = n2;
    n0->random = n2;
    Solution s;
    s.copyRandomList(n0);

    return 0;
}