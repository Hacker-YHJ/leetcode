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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* t = new ListNode(0);
    t->next = head;
    ListNode* res = t;
    ListNode* c = head;
    while (c) {
      if (c->val == val) {
        t->next = c->next;
      } else {
        t = c;
      }
      c = c->next;
    }
    return res->next;
  }
};
