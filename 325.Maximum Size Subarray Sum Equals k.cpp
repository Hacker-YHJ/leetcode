class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int curr = 0, res = 0;
    for (int i = 0; i < nums.size(); i++) {
      curr += nums[i];
      if (curr == k) {
        res = i + 1;
      } else if (m.find(curr - k) != m.end()) {
        res = max(res, i - m[curr - k]);
      }
      if (m.find(curr) == m.end()) {
        m[curr] = i;
      }
    }
    return res;
  }
};
