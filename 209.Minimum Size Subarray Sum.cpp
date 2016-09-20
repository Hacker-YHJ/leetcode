class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size(), s = 0, e = 0, sum = 0, res = 0x7FFFFFFF;
        while (e != size || sum >= target) {
            while (e < size && sum < target) sum += nums[e++];
            while (sum >= target) {
                res = e - s < res ? e - s : res;
                sum -= nums[s++];
            }
        }
        return res == 0x7FFFFFFF ? 0 : res;
    }
};

// 4ms 28%
