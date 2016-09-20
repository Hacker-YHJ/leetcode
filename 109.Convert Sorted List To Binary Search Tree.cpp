/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    TreeNode* h;
    ListNode* mid = head;
    ListNode* midPrev = nullptr;
    ListNode* t = head;
    while (t && t -> next) {
      t = t -> next -> next;
      midPrev = mid;
      mid = mid -> next;
    }
    h = new TreeNode(mid->val);
    if (head != mid) {
      midPrev -> next = nullptr;
      h -> left = sortedListToBST(head);
    } else {
      h -> left = nullptr;
    }
    h -> right = sortedListToBST(mid->next);
    return h;
  }
};
