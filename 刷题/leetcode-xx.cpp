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
        ListNode* fast_cur = head;
        ListNode* slow_cur = head;
        // 由于要删除，所以多减一个1
        while (n-1-1 > 0) {
            fast_cur = fast_cur->next;
            n--;
        }
        while (fast_cur->next != NULL) {
            fast_cur = fast_cur->next;
            slow_cur = slow_cur->next;
        }
        if (slow_cur != head) {
            ListNode* del = slow_cur->next;
            slow_cur->next = del->next;
            delete del;
            return head;
        } else {
            ListNode* res = slow_cur->next;
            delete head;
            return res;
        }
        
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
    ListNode* res = s.removeNthFromEnd(node1, 2);
    cout << res->val << endl;
    return 0;
}