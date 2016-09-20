/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* p = headA;
    struct ListNode* q = headB;
    if (p == NULL || q == NULL) return NULL;
    
    while (p != NULL && q != NULL & p != q) {
        p = p -> next;
        q = q -> next;
        if (p == q) return p;
        if (p == NULL) p = headB;
        if (q == NULL) q = headA;
    }
    
    return p;
}

// 32ms 20%
