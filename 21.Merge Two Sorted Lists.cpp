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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* h = new ListNode(0);
    h->next = l1;
    ListNode* prev = h;
    while (l1 && l2) {
      if (l1->val >= l2->val) {
        ListNode* t = l2->next;
        prev->next = l2;
        l2->next = l1;
        prev = l2;
        l2 = t;
      } else {
        prev = l1;
        l1 = l1 -> next;
      }
    }
    if (l2) {
      prev->next = l2;
    }
    return h->next;
  }
};
