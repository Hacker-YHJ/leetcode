class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0, size = nums.size(); i < size-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < size-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int p = j+1, q = size-1, t = target - nums[j] - nums[i];
                while (p < q) {
                    if (nums[p] + nums[q] == t) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[p], nums[q]});
                        while (p < q && nums[p+1] == nums[p]) ++p;
                        while (p < q && nums[q-1] == nums[q]) --q;
                        ++p; --q;
                    }
                    else if (nums[p] + nums[q] < t) ++p;
                    else --q;
                }
            }
        }
        return res;
    }
};

//92 ms 62%
