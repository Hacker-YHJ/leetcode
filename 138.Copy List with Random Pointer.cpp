/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) return NULL;
        RandomListNode *t = head;
        RandomListNode *nhead, *nt;
        while (NULL != t) {
            nt = new RandomListNode(t->label);
            nt->next = t->next;
            t->next = nt;
            t = nt->next;
        }
        t = head;
        while (NULL != t) {
            t->next->random = NULL != t->random ? t->random->next : NULL;
            t = t->next->next;
        }
        t = head;
        nhead = head->next;
        while (NULL != t) {
            nt = t->next->next;
            t->next->next = NULL != nt ? nt->next : NULL;
            t->next = nt;
            t = nt;
        }
        return nhead;
    }
};
//108ms 87%
