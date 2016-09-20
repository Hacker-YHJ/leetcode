class Solution {
private:
    int* arr;
    int size;
protected:
    static vector<int> discretize(vector<int>& nums) {
        vector<int> res = nums;
        vector<int> ordered = nums;
        map<int, int> m;
        sort(ordered.begin(), ordered.end());
        int count = 1;
        for (auto i = ordered.begin(), j = ordered.end(); i != j; ++i) m.insert(pair<int, int>{*i, count++});
        for (auto i = res.begin(), j = res.end(); i != j; ++i) *i = m[*i];
        return res;
    }
    static int lowbit(int x) {
        return x&(-x);
    }
    void init(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) arr[i] = 0;
    }
    void update(int pos, int val) {
        while (pos < size) {
            arr[pos] += val;
            pos += lowbit(pos);
        }
    }
    int get(int pos) {
        int res = 0;
        while (pos) {
            res += arr[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> discrete = discretize(nums);
        init(discrete.size()+1);
        for (int i = discrete.size()-1, j = 0; i >= j; --i) {
            update(discrete[i], 1);
            discrete[i] = get(discrete[i]-1);
        }
        
        return discrete;
    }
};
// 72ms 28%
