/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 # include <stdio.h>
 # include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void mergeSubLists(struct ListNode* tail, struct ListNode* sub1, struct ListNode* sub2) {
    if (sub1 == NULL) {
        tail->next = sub2;
        return;
    } else if (sub2 == NULL) {
        tail->next = sub1;
        return;
    }

    if (sub1->val < sub2->val) {
        tail->next = sub1;
        tail = sub1;
        sub1 = sub1->next;
        mergeSubLists(tail, sub1, sub2);
        return;
    } else {
        tail->next = sub2;
        tail = sub2;
        sub2 = sub2->next;
        mergeSubLists(tail, sub1, sub2);
        return;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    mergeSubLists(tail, l1, l2);
    return head->next;
}

void printList(struct ListNode* head) {
    for (struct ListNode *cur = head ; cur != NULL ; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("end\n");
}

int main(){
    struct ListNode* a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    a1->val = 1;
    a2->val = 2;
    a3->val = 3;
    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;
    struct ListNode* b1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    b1->val = 4;
    b2->val = 5;
    b3->val = 6;
    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;
    printList(a1);
    printList(b1);
    // struct ListNode *head = mergeTwoLists(a1, b1);
    struct ListNode *head = mergeTwoLists(NULL, NULL);
    printList(head);
    return 0;
}