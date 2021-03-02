# include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 难度在于需要找到入环点
    // 快慢指针同时从head开始出发
    // 首先，快慢指针在环内相遇时，slow一定还没有走完一圈
        // 证明：
        // 假设，极端情况下，整个链表是一个环，即入环点在head
        // slow走完半圈时fast已经走完一圈，slow走完一圈时fast走完两圈，快慢指针相遇在head处再次相遇
        // 对于入环点不在head的一般情况，在slow入环时，fast已经先走了一段路程，那么必然会在slow回到入环点之前追上slow
        //（也有可能fast已经走完一圈，此时情况与上面假设相同，快慢指针会再次在入环点相遇）
    // 假设快慢指针相遇时，slow已经走过的距离为a，距离回到入环点的距离为b，head距离入环点的距离为c
    // 那么fast走过的距离为 2a + b + c
    // slow走过的距离为 a + c
    // 由于fast走过的距离时slow走过距离的两倍
    // 则有 2a + b + c = 2 * (a + c)
    //     2a + b + c = 2a + 2c
    //              b = c
    // 即此时slow距离入环点的距离与head距离入环点的距离相同
    // 因此在快慢指针相遇时，再让一指针从head出发与slow速度相同，则两指针会在入环点处相遇
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            } else {
                return NULL;
            }
        } while(slow != fast);
        ListNode* ptr = head;
        while (ptr != slow) {
            ptr = ptr->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    return 0;
}