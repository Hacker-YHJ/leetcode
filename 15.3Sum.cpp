class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0, j = nums.size(); i < j-2; ++i) {
            if (0 != i && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int p = i+1, q = j-1;
            while (p != q) {
                if (nums[p] + nums[q] == target) {
                    res.push_back(vector<int>{nums[i], nums[p], nums[q]});
                    while (p != q && nums[p+1] == nums[p]) ++p;
                    while (p != q && nums[q-1] == nums[q]) --q;
                    if (p != q) ++p;
                }
                else if (nums[p] + nums[q] < target) ++p;
                else --q;
            }
        }
        return res;
    }
};
//52ms 80%
