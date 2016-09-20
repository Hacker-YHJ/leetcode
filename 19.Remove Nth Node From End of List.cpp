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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* h = new ListNode(0);
    h -> next = head;
    ListNode* fast = head;
    ListNode* prev = h;
    ListNode* t = head;
    while (n-- > 0) {
      if (!fast) return head;
      fast = fast -> next;
    }
    while (fast) {
      prev = t;
      t = t -> next;
      fast = fast -> next;
    }
    prev->next = t->next;
    return h -> next;
  }
};
