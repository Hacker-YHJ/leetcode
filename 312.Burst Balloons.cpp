class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        if (0 == N) return 0;
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int arr[N+2][N+2] = {0};
        
        for (int len = 0; len < N; ++len) {
            for (int s = 1; s+len <= N; ++s) {
                int maxCount = 0;
                for (int i = s, j = s+len; i <= j; ++i) {
                    int tmp = arr[s][i-1] + arr[i+1][j] + nums[s-1]*nums[i]*nums[j+1];
                    maxCount = maxCount > tmp ? maxCount : tmp;
                }
                arr[s][s+len] = maxCount;
            }
        }
        return arr[1][N];
    }
};

// 20ms 87%
