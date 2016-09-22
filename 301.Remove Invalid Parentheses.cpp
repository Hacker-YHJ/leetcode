class Solution {
private:
    vector<string> res;
    bool isValid(string s) {
        int count = 0;
        for (const auto& c : s) {
            count += c == '(';
            count -= c == ')';
            if (count < 0) return false;
        }
        return count == 0;
    }
    pair<int, int> init(string s) {
        auto p = make_pair(0, 0);
        for (const auto& c : s) {
            p.first += c == '(';
            p.first || (p.second += c == ')');
            !p.first || (p.first -= c == ')');
        }
        return p;
    }
    void dfs(string s, int start, int l, int r) {
        if (!(l || r)) {
            if (isValid(s)) res.push_back(s);
        } else {
            for (int i = start; i < s.size(); ++i) {
                string tmp = s;
                if(r == 0 && l > 0 && tmp[i] == '(') {
                    if(i == start || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, l - 1, r);
                    }
                }
                if(r > 0 && tmp[i] == ')') {
                    if(i == start || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, l, r - 1);
                    }
                }
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        auto count = init(s);
        dfs(s, 0, count.first, count.second);
        return res;
    }


};
