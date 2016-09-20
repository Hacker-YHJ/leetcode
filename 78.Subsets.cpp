class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto len = nums.size();
        
        for (auto i = 0; i < 1 << len; ++i) {
            vector<int> tmp;
            auto count = 0;
            auto flag = i;
            while (flag) {
                if (flag&1) tmp.push_back(nums[count]);
                ++count;
                flag >>= 1;
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// 8ms 9%
