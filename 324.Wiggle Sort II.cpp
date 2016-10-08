class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();
    nth_element(nums.begin(), nums.begin() + size / 2, nums.end());
    int mV = nums[size / 2];
    int i = (size - 1) / 2 * 2, j = i, k = 1;
    for (int c = 0; c < size; ++c) {
      if (nums[j] < mV) {
        swap(nums[i], nums[j]);
        i -= 2;
        j -= 2;
        if (j < 0) j = size / 2 * 2 - 1;
      } else if (nums[j] > mV) {
        swap(nums[j], nums[k]);
        k += 2;
      } else {
        j -= 2;
        if (j < 0) j = size / 2 * 2 - 1;
      }
    }
  }
};
