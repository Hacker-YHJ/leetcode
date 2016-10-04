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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> heap;
    ListNode* root = new ListNode(0);
    ListNode* curr = root;
    for (auto const& node : lists) {
      if (node) heap.push_back(node);
    }
    auto comp = [](ListNode* const& a, ListNode* const& b) { return a->val > b->val; };
    make_heap(heap.begin(), heap.end(), comp);
    while (!heap.empty()) {
      curr->next = heap.front();
      curr = curr->next;
      pop_heap(heap.begin(), heap.end(), comp);
      heap.pop_back();
      if (curr->next) {
        heap.push_back(curr->next);
        push_heap(heap.begin(), heap.end(), comp);
      }
    }
    return root->next;
  }
};
