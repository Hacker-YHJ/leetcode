class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m = INT_MAX, n = INT_MAX;
        for (auto i : nums) {
            if (i <= m) {
                m = i;
            }
            else if (i <= n) {
                n = i;
            }
            else return true;
        }
        return false;
    }
};

// 8ms 16%
