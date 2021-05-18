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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_head = new ListNode();
        ListNode* res_cur = res_head;
        int new_val = 0;
        
        while (l1 != NULL && l2 != NULL) {
            new_val += (l1->val + l2->val);
            res_cur->next = new ListNode(new_val%10);
            res_cur = res_cur->next;
            if (new_val >= 10) new_val = 1;
            else new_val = 0;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* longList = NULL;
        if (l1 == NULL && l2 == NULL) {
            if (new_val == 1) res_cur->next = new ListNode(1);
            return res_head->next;
        } else if (l1 == NULL) longList = l2;
        else longList = l1;
        
        while (longList != NULL) {
            new_val += longList->val;
            res_cur->next = new ListNode(new_val%10);
            res_cur = res_cur->next;
            if (new_val >= 10) new_val = 1;
            else new_val = 0;
            longList = longList->next;
        }

        if (new_val == 1) res_cur->next = new ListNode(1);
        return res_head->next;

    }
};

int main(int argc, char const *argv[])
{
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;
    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(6);
    ListNode* l7 = new ListNode(9);
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = NULL;
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l4);
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
