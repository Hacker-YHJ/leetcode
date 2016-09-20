/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(NULL == head) return NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    do {
        if(NULL == fast || NULL == (fast -> next)) return NULL;
        slow = slow -> next;
        fast = fast -> next -> next;
    } while(fast != slow);
    fast = head;
    while (fast != slow) {
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

// 4ms 31%
