/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  ListNode* r;
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) : r(head) {
    srand(NULL);
  }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* c = r;
    int res;
    int count = 1;
    while (c) {
      (rand() % count++ != 0) || (res = c->val);
      c = c->next;
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
