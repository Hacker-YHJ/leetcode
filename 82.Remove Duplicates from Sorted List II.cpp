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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *root = new ListNode(0);
    root->next = head;
    ListNode *prev = root;
    ListNode *t = head;
    while (t) {
      if (t->next && t->next->val == t->val) {
        ListNode *n = t;
        while (n && n->val == t->val) n = n->next;
        prev->next = t = n;
      } else {
        prev = t;
        t = t->next;
      }
    }
    return root->next;
  }
};
