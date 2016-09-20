bool match(char* s, int si, int sl, char* p, int pi, int pl) {
    if (si == sl) return pi == pl;
    if (pi > pl) return false;
    bool result = false;
    if (si + 1 == sl || s[si+1] != '*') {
        if (s[si] == '.') return match(s, si+1, sl, p, pi+1, pl);
        else return s[si] != p[pi] ? false : match(s, si+1, sl, p, pi+1, pl);
    }
    else {
        if (s[si] == '.') {
            // for (int i = pi; i <= pl; ++i) {
            for (int i = pl; i >= pi; --i) {
                result |= match(s, si+2, sl, p, i, pl);
                if (result) break;
            }
        }
        else {
            result |= match(s, si+2, sl, p, pi, pl);
            if (result) return result;
            int i = pi;
            while (p[i] == s[si]) {
                result |= match(s, si+2, sl, p, i+1, pl);
                if (result) break;
                ++i;
            }
        }
        return result;
    }
}

bool isMatch(char* s, char* p) {
    int slen = strlen(s), plen = strlen(p);
    return match(p, 0, plen, s, 0, slen);
}

// 28 ms
