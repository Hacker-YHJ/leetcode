class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k < 1 || t < 0) return false;
    unordered_map<long, long> m;
    for (int i = 0; i < nums.size(); i++) {
      long key = (long) nums[i] - numeric_limits<int>::min();
      long bucket = key / ((long) t + 1);
      if (m.find(bucket) != m.end() ||
          m.find(bucket - 1) != m.end() && key - m[bucket - 1] <= t ||
          m.find(bucket + 1) != m.end() && m[bucket + 1] - key <= t)
        return true;
      if (m.size() >= k) {
        long last = ((long) nums[i - k] - numeric_limits<int>::min()) / ((long) t + 1);
        m.erase(last);
      }
      m[bucket] = key;
    }
    return false;
  }
};
