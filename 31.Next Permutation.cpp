class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    auto i = nums.end() - 1;
    if (nums.begin() == i) return;
    auto j = i - 1;
    while (i != nums.begin()) {
      if (*j < *i) {
        auto k = nums.end();
        while (*j >= *--k);
        iter_swap(j, k);
        reverse(i, nums.end());
        return;
      }
      i = j--;
    }
    reverse(nums.begin(), nums.end());
    return;
  }
};
