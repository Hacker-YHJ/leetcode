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
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *p = head, *c = head->next;
    while (c) {
      ListNode *tmp = c->next;
      c->next = p;
      p = c;
      c = tmp;
    }
    head->next = nullptr;
    return p;
  }
};
