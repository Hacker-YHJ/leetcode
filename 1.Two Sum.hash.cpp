class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0, j = nums.size(); i < j; ++i) {
      if (m.find(target - nums[i]) != m.end()) {
        return {m[target-nums[i]], i};
      }
      m[nums[i]] = i;
    }
    return {};
  }
};
