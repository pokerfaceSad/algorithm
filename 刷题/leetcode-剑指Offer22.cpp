/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast_cur = head;
        ListNode* slow_cur = head;
        int step_count = 0;
        while (fast_cur->next != NULL) {
            if (step_count < k-1) {
                fast_cur = fast_cur->next;
                step_count++;
            } else {
                fast_cur = fast_cur->next;
                slow_cur = slow_cur->next;
            }
        }
        return slow_cur;

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
    ListNode* res = s.getKthFromEnd(node1, 1);
    cout << res->val << endl;
    return 0;
}