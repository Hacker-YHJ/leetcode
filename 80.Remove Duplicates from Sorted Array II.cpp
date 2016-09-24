class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int idx = 1;
    int res = 1;
    int count = 0;
    for (int i = 1, j = nums.size(); i < j; ++i) {
      if (nums[i] == nums[res-1]) {
        ++count;
        if (count > 1) continue;
      }
      else {
        count = 0;
      }
      swap(nums[res], nums[i]);
      res++;
    }
    return res;
  }
};
