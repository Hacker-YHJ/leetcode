class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int arr[target];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < target; ++i) {
      for (const auto& n : nums) {
        if (n > i + 1) break;
        else if (n == i + 1) arr[i] += 1;
        else arr[i] += arr[i - n];
      }
    }
    return arr[target-1];
  }
};
