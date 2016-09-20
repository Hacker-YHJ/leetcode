class NumArray {
private:
    int *arr;
    int len;
    vector<int> f;
protected:
    int lowbit(int i) {
        return i&(-i);
    }
    int sum(int i) {
        int res = 0;
        while (i) {
            res += arr[i];
            i -= lowbit(i);
        }
        return res;
    }
public:
    NumArray(vector<int> &nums) {
        len = nums.size()+1;
        arr = new int[len];
        f = nums;
        
        arr[0] = 0;
        for (auto i = 1; i < len; ++i) {
            arr[i] = 0;
            for (auto j = i, k = i - lowbit(i) + 1; j >= k; --j) {
                arr[i] += f[j-1];
            }
        }
    }

    void update(int i, int val) {
        int index = i+1;
        while (index < len) {
            arr[index] += val - f[i];
            index += lowbit(index);
        }
        f[i] = val;
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
// 1800ms 1.75%
