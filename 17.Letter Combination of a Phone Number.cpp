class Solution {
private:
    vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string val;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        res.clear();
        val = digits;
        dfs(digits, 0);
        return res;
    }
    void dfs(const string& digits, int digit) {
        if (digit >= digits.size()) {
            res.push_back(string(val));
            return;
        }
        const string& candidate = m[digits[digit]-'2'];
        int len = candidate.size();
        for (int i = 0; i < len; ++i) {
            val[digit] = candidate[i];
            dfs(digits, digit+1);
        }
    }
};

// 0ms 8%
