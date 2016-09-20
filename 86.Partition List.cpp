/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0x80000000);
        p1->next = head;
        ListNode* hh = p1;
        ListNode* c1 = head;
        if (!head) return hh->next;
        ListNode* n1 = head->next;
        
        while (c1->val < x && n1) {
            p1 = c1;
            c1 = n1;
            n1 = n1->next;
        }
        if (!n1) return hh->next;
        ListNode* p2 = c1;
        ListNode* c2 = n1;
        ListNode* n2 = n1->next;
        while (c2) {
            if (c2->val >= x) {
                p2 = c2;
                c2 = n2;
                n2 = n2 ? n2->next : NULL;
                continue;
            }
            p2->next = n2;
            p1->next = c2;
            c2->next = c1;
            p1 = c2;
            c2 = n2;
            n2 = n2 ? n2->next : NULL;
            
        }
        return hh->next;
    }
};

//8ms 6.35%
