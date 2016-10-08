class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    nums.insert(nums.begin(), numeric_limits<int>::min());
    nums.insert(nums.end(), numeric_limits<int>::min());
    auto s = nums.begin() + 1;
    auto e = nums.end() - 1;
    auto mid = s + (e - s) / 2;
    while (*mid <= *(mid - 1) || *mid <= *(mid + 1)) {
      if (*mid <= *(mid - 1)) {
        e = mid;
      } else {
        s = mid + 1;
      }
      mid = s + (e - s) / 2;
    }
    return distance(nums.begin(), mid) - 1;
  }
};
