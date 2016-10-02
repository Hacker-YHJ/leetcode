class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.empty()) return 0;
        int size = nums.size();
        long arr[size][2];
        long sum[size];
        sum[0] = nums[0];
        arr[0][0] = nums[0];
        for (int i = 1; i < size; ++i) {
            sum[i] = nums[i] + sum[i - 1];
            arr[i][0] = sum[i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = i; j < size; ++j) {
                long minSum = numeric_limits<long>::max();
                int s = i - 1;
                int e = j - 1;
                int mid = s + (e - s) / 2;
                while (e - s > 5) {
                    if (arr[mid][0] < sum[j] - sum[mid]) {
                        s = mid;
                    } else {
                        e = mid + 1;
                    }
                    mid = s + (e - s) / 2;
                }
                for (int k = s; k <= e; ++k) {
                    minSum = min(minSum, max(arr[k][0], sum[j] - sum[k]));
                }
                arr[j][1] = minSum;
            }
            for (int j = 0; j < size; ++j) {
                arr[j][0] = arr[j][1];
            }
        }
        return arr[size-1][0];
    }
};
