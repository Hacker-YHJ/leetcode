/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  int* arr;
  int n;
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    n = 0;
    auto t = head;
    while (t) {
      t = t->next;
      ++n;
    }
    arr = new int[n];
    t = head;
    n = 0;
    while (t) {
      arr[n++] = t->val;
      t = t->next;
    }
    srand(NULL);
  }

  /** Returns a random node's value. */
  int getRandom() {
    return arr[rand() % n];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
