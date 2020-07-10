# include <stdio.h>

 struct ListNode {
    int val;
    struct ListNode *next;
 };


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    struct ListNode* pnext = head->next;
    head->next = swapPairs(head->next->next);
    pnext->next = head;
    return pnext;
}

void printLinkList(struct ListNode* head) {
    while(head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("end\n");
}

int main() {
    struct ListNode node1, node2, node3, node4;
    struct ListNode *p1 = &node1, *p2 = &node2, *p3 = &node3, *p4 = &node4;
    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;
    printLinkList(p1);
    struct ListNode* newhead = swapPairs(p1);
    printLinkList(newhead);
    return 0;
 }

