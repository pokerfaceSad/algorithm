# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        ListNode* tmp;
        while (head != NULL) {
            tmp = head->next;
            head->next = new_head;
            new_head = head;
            head = tmp;
        }
        return new_head;
        
    }
};