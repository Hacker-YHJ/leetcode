class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int res = 0;
    for (int i = 0, j = nums.size(); i < j; ++i) {
      if (nums[i] == val) continue;
      swap(nums[res], nums[i]);
      res++;
    }
    return res;
  }
};
