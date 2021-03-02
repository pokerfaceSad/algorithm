# include <iostream>
using namespace std;
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        // 快慢指针
        // 慢指针走一步 快指针走两步
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tail = NULL;
        tail = reverse(slow->next);
        while (tail != NULL && head != NULL) {
            if (tail->val != head->val) {
                return false;
            }
            tail = tail->next;
            head = head->next;
        }
        return true;
    }

    // 翻转链表并返回头指针
    ListNode* reverse(ListNode* head) {
        ListNode* old_head = head;
        ListNode* new_head = NULL;
        ListNode* temp = NULL;
        while (old_head != NULL) {
            temp = old_head;
            old_head = old_head->next;
            temp->next = new_head;
            new_head = temp;
        }
        return new_head;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    node1->next = NULL;
    Solution s;
    cout << s.isPalindrome(node1) << endl;
    return 0;
}