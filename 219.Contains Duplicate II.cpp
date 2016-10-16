class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> s;
    for (int i = 0, j = nums.size(); i < j; ++i) {
      auto it = s.find(nums[i]);
      if (it != s.end() && abs(it->second - i) <= k) return true;
      s[nums[i]] = i;
    }
    return false;
  }
};
