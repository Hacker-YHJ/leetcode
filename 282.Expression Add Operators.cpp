class Solution {
    vector<string> res;
    string num;
    int target;
    void dfs(string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i=pos+1; i<=num.size(); i++) {
                if (i - pos > 1 && num[pos] == '0') break;
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                dfs(cur+'+'+t, i, cv+now, now, '+');
                dfs(cur+'-'+t, i, cv-now, now, '-');
                dfs(cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }
public:
    vector<string> addOperators(string _num, int _target) {
        num = _num;
        target = _target;
        if (num.empty()) return {};
        for (int i = 1; i <= num.size(); i++) {
            if (i > 1 && num[0] == '0') break;
            string s = num.substr(0, i);
            long cur = stol(s);
            dfs(s, i, cur, cur, '#');
        }
        return res;
    }
};
