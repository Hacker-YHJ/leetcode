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
    ListNode* root = h;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        h->next = l2;
        h = l2;
        l2 = l2->next;
      } else {
        h->next = l1;
        h = l1;
        l1 = l1->next;
      }
    }
    if (l1) {
      h->next = l1;
    } else {
      h->next = l2;
    }
    return root->next;
  }
};
