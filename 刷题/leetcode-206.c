# include <stdio.h>
# include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    // 新链表的尾节点
    struct ListNode* tail = head;
    struct ListNode* tmp = NULL;
    while (tail != NULL && tail->next != NULL) {
        // 保存原头节点
        tmp = head;
        // 头节点指针向后移动
        head = tail->next;
        // 尾节点的next指针指向剩余链表的头节点
        tail->next = head->next;
        // 逆转
        head->next = tmp;
    }
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* next = head;
    while (next != NULL) {
        printf("val=%d->", next->val);
        next = next->next;
    }
    printf("end\n");
}

int main() {
    struct ListNode node1, node2, node3;
    struct ListNode *p1 = &node1, *p2 = &node2, *p3 = &node3;
    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL; 
    printList(p1);
    struct ListNode* p = reverseList(p1);
    printList(p);
    return 0;
}
