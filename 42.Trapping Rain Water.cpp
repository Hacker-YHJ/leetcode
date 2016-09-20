class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int tmp = 0;
        int size = height.size();
        int leftMost = 0;
        int leftMostI = size;
        for (int i = 0; i < size; ++i) {
            if (height[i] >= leftMost) {
                res += tmp;
                tmp = 0;
                leftMost = height[i];
                leftMostI = i;
            }
            else tmp += leftMost - height[i];
        }
        leftMost = 0;
        tmp = 0;
        for (int i = size-1; i >leftMostI; --i) {
            if (height[i] >= leftMost) {
                res += tmp;
                tmp = 0;
                leftMost = height[i];
            }
            else tmp += leftMost - height[i];
        }
        res += tmp;
        return res;
    }
};
// 4ms 28%
