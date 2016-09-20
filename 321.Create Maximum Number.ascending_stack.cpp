class Segment {
  private:
    int *tree;
    int *tIndex;
    int size;
    
    int build(vector<int> &nums, int s, int e, int index) {
        if (s == e-1) {
            tree[index] = nums[s];
            tIndex[index] = s;
            return nums[s];
        }
        int p = (e-s)/2+s;
        int l = build(nums, s, p, index*2+1);
        int r = build(nums, p, e, index*2+2);
        tree[index] = l > r ? l : r;
        tIndex[index] =  l >= r ? tIndex[index*2+1] : tIndex[index*2+2];
        return tree[index];
    }
    pair<int, int> query(int i, int s, int e, int l, int r) {
        if (s == l && e == r) return pair<int, int>{tree[i], tIndex[i]};
        int p = (r-l)/2+l;
        if (e <= p) return query(i*2+1, s, e, l, p);
        else if (s >= p) return query(i*2+2, s, e, p, r);
        else {
            pair<int, int> lmax = query(i*2+1, s, p, l, p);
            pair<int, int> rmax = query(i*2+2, p, e, p, r);
            return lmax.first >= rmax.first ? lmax : rmax;
        }
    }
  public:
    int osize;
    Segment(vector<int> &nums) {
        size = 1;
        osize = nums.size();
        while (size < osize) size <<= 1;
        size <<= 1;
        
        tree = new int[size];
        tIndex = new int[size];
        if (osize > 0) build(nums, 0, osize, 0);
    }
    pair<int, int> get(int s, int e) {
        return query(0, s, e, 0, osize);
    }
};
class Solution {
protected:
    static vector<int> getMax(Segment s, int n) {
        vector<int> res(n);
        int last = -1;
        for (int i = 0; i < n; ++i) {
            pair<int, int> tmp = s.get(last+1, s.osize-n+i+1);
            res[i] = tmp.first;
            last = tmp.second;
        }
        return res;
    }
    static vector<int> getMax(vector<int> &s, int n) {
        vector<int> res(0);
        int count = 0;
        int ss = s.size();
        while (n - res.size() < ss - count) {
            int tmp = s[count++];
            while (!res.empty() && n - res.size() < ss - count + 1 && res.back() < tmp) res.pop_back();
            if (res.size() < n) res.push_back(tmp);
        }
        while (count < ss) {
            res.push_back(s[count++]);
        }
        return res;
    }
    static bool greater(vector<int> &a, int i, vector<int> &b, int j) {
        int as = a.size(), bs = b.size();
        while (i < as && j < bs && a[i] == b[j]) {
            i++;
            j++;
        }
        return j == bs || (i < as && a[i] > b[j]);
    }
    static bool greater(vector<int> &a, vector<int> &b) {
        int as = a.size(), bs = b.size();
        for (int i = 0; i < as; ++i) {
            if (a[i] < b[i]) return false;
            else if (a[i] > b[i]) return true;
        }
        return false;
        
    }
    static vector<int> merge(vector<int>& a, vector<int>& b) {
        int as = a.size(), bs = b.size(), count = 0, ac = 0, bc = 0;
        vector<int> res(as+bs);
        while (count < as+bs) {
            if (ac < as && bc < bs) {
                if (greater(a, ac, b, bc)) {
                    res[count++] = a[ac++];
                }
                else {
                    res[count++] = b[bc++];
                }
            }
            else if (ac == as) res[count++] = b[bc++];
            else res[count++] = a[ac++];
        }
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // Segment s1(nums1);
        // Segment s2(nums2);
        vector<int> res(k, 0);
        int l1 = nums1.size();
        int l2 = nums2.size();
        int s = k < l1 ? k : l1;
        int e = k < l2 ? 0 : k - l2;
        for (int i = s; i >= e; --i) {
            vector<int> m1 = getMax(nums1, i);
            vector<int> m2 = getMax(nums2, k-i);
            // vector<int> m1 = getMax(s1, i);
            // vector<int> m2 = getMax(s2, k-i);
            
            vector<int> tmpMax = merge(m1, m2);
            if (greater(tmpMax, res)) res = tmpMax;
        }
        return res;
    }
};

// 132ms 52%
