class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int idx = 1;
    int res = 1;
    for (int i = 1, j = nums.size(); i < j; ++i) {
      if (nums[i] == nums[res-1]) continue;
      swap(nums[res], nums[i]);
      res++;
    }
    return res;
  }
};
