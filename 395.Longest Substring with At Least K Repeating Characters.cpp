class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        if (len < k) return 0;
        int m[26];
        for (int i = 0; i < 26; ++i) m[i] = 0;
        int least = 0x7FFFFFFF;
        int least_idx = 0;
        for (int i = 0; i < len; ++i) m[s[i] - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (m[i] != 0 && least > m[i]) {
                least = m[i];
                least_idx = i;
            }
        }
        if (least >= k) return len;
        else {
            int res = 0;
            int t = 0;
            int tmp;
            for (int i = 0; i < len; ++i) {
                if (s[i] == least_idx + 'a') {
                    tmp = longestSubstring(s.substr(t, i - t), k);
                    res = res > tmp ? res : tmp;
                    t = i + 1;
                }
            }
            tmp = longestSubstring(s.substr(t, len - t), k);
            res = res > tmp ? res : tmp;
            return res;
        }
    }
};
