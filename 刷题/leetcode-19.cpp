/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast_cur = head;
        // slow_cur->next指向要删除的节点
        ListNode* slow_cur = dummy;
        while (n > 0) {
            fast_cur = fast_cur->next;
            n--;
        }
        while (fast_cur != NULL) {
            fast_cur = fast_cur->next;
            slow_cur = slow_cur->next;
        }
        slow_cur->next = slow_cur->next->next;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};


int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    ListNode* cur = node1;
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    Solution s;
    ListNode* res = s.removeNthFromEnd(node1, 1);
    cur = res;
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
}
    return 0;
}