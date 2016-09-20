class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int i = 0, m = 0;
        while (i <= m) {
            m = i + nums[i] > m ? i + nums[i] : m;
            ++i;
            if (m >= len-1) return true;
        }
        return false;
    }
};

// 16ms 9.56%
