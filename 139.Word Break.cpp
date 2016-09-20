class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        if (size == 0) return false;
        
        bool arr[size] = {false};
        for (int i = 0; i < size; ++i) {
            if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
                arr[i] = true;
                continue;
            }
            for (int j = i-1; j >=0; --j) {
                if (arr[j] && wordDict.find(s.substr(j+1, i-j)) != wordDict.end()) {
                    arr[i] = true;
                    break;
                }
            }
        }
        return arr[size-1];
    }
};

// 4ms 82%
