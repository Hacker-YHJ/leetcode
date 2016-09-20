class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool m[256] = {false};
        int st = 0, ed = 1, ans = 0;
        for (int j = s.size(); ed <= j;++ed) {
            while (m[s[ed-1]]) m[s[st++]] = false;
            m[s[ed-1]] = true;
            if (ed - st > ans) ans = ed - st;
        }
        return ans;
    }
};

// 16ms 64%
