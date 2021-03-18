# include <iostream>
# include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* post = head->next;
        ListNode* cur = head;
        while (post != NULL) {
            if (post->val == val) cur->next = post->next; 
            cur = post;
            post = post->next;
        }
        return head;
    }
};

int main() {
    return 0;
}