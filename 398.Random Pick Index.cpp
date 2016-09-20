class Solution {
private:
    vector<int> r;
public:
    Solution(vector<int> nums) {
        r = nums;
        srand(time(NULL));
    }

    int pick(int target) {
        int cnt = 0;
        int idx = -1;
        for (int i = 0, j = r.size(); i < j; ++i) {
            if (r[i] == target) {
                ++cnt;
                if (idx == -1) {
                    idx = i;
                } else {
                    idx = rand() % cnt ? idx : i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
