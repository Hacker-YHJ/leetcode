class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        string res;
        int size = target.size();
        for (int i = 0; i <= size; ++i) {
            vector<bool> p(size, false);
            fill(p.begin(), p.begin() + i, true);
            do {
                string abbr;
                int count = 0;
                bool flag = true;
                for (int i = 0; i < size; ++i) {
                    if (p[i]) {
                        if (count > 0) {
                            abbr += to_string(count);
                            count = 0;
                        }
                        abbr = abbr += target[i];
                    } else {
                        count++;
                    }
                }
                if (count > 0) {
                    abbr += to_string(count);
                }
                for (const auto& w : dictionary) {
                    flag = flag && !validWordAbbreviation(w, abbr);
                    if (!flag) break;
                }
                if (flag) {
                    if (res.empty()) res = abbr;
                    else if (res.size() > abbr.size()) res = abbr;
                }
            } while (prev_permutation(p.begin(), p.end()));
            if (!res.empty()) return res;
        }
        return res;
    }
    bool validWordAbbreviation(string word, string abbr) {
        int aS = abbr.size();
        int wS = word.size();
        int i = 0, j = 0;
        int count = 0;
        while (j < aS && i < wS) {
            if (abbr[j] >= '0' && abbr[j] <= '9') {
                count = count * 10 + abbr[j] - '0';
                ++j;
                if (count == 0) return false;
                continue;
            } else {
                if (count > 0) {
                    i += count;
                    count = 0;
                    continue;
                }
                if (word[i++] != abbr[j++]) return false;
            }
        }
        if (count > 0 && j == aS && i + count == wS) return true;
        if (count == 0 && j == aS && i == wS) return true;
        return false;
    }
};
