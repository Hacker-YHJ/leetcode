class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k < 0 || k > n) return {};
        vector<bool> p(n, false);
        fill(p.begin(), p.begin() + k, true);
        vector<vector<int> >res;
        do {
            vector<int> tmp;
            for (int i = 1; i <= n; ++i) {
                if (p[i-1]) tmp.push_back(i);
            }
            res.push_back(tmp);
        } while (prev_permutation(p.begin(), p.end()));
        return res;
    }
};
