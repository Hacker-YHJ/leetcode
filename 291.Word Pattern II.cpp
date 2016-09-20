class Solution {
public:
    unordered_map<char, string> pDict;
    unordered_map<string, char> sDict;
    string p;
    string str;
    int m, n;
    
    bool wordPatternMatch(string pattern, string str) {
        pDict.clear();
        sDict.clear();
        this -> p = pattern;
        this -> str = str;
        m = p.size();
        n = str.size();
        return match(0, 0);
    }

    bool match(int i, int j) {
        if (i == m && j == n) return true;
        if (i >= m || j >= n) return false;
        bool ins = false;
        string s;
        
        if (pDict.find(p[i]) != pDict.end()) {
            int tSize = pDict[p[i]].size();
            s = str.substr(j, tSize);
            if (pDict[p[i]] != s || sDict[s] != p[i]) return false;
            return match(i + 1, j + tSize);
        }
        
        for (int k = j; k < n; ++k) {
            s = str.substr(j, k - j + 1);
            if (sDict.find(s) != sDict.end()) continue;
            pDict[p[i]] = s;
            sDict[s] = p[i];
            if (match(i + 1, k + 1)) return true;
            sDict.erase(s);
        }
        pDict.erase(p[i]);
        return false;
    }
};

//300 ms 30%
