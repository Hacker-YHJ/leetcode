class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0, lowbit = 0, a = 0, b = 0;
        for (auto i = nums.begin(), j = nums.end(); i != j; ++i) {
            xr ^= *i;
        }
        lowbit = xr&(-xr);
        for (auto i = nums.begin(), j = nums.end(); i != j; ++i) {
            if (*i & lowbit) a ^= (*i);
            else b ^= (*i);
        }
        vector<int> res { a,b };
        return res;
    }
};

//20ms 26%
