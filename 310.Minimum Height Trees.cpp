class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> g(n);
        queue<int> tmp;
        vector<int> result;
        if (0 == n) return result;
        if (1 == n) {
            result.push_back(0);
            return result;
        }
        for (auto i = edges.begin(); i != edges.end(); ++i) {
          g[(*i).first].insert((*i).second);
          g[(*i).second].insert((*i).first);
        }
        for (auto i = 0; i < n; ++i) {
          if (1 == g[i].size()) {
            tmp.push(i);
          }
        }
        while (!tmp.empty()) {
          result.clear();
          auto size = tmp.size();
          while (size--) {
            auto f = tmp.front();
            result.push_back(f);
            tmp.pop();
            for (auto it = g[f].begin(); it != g[f].end(); ++it) {
              g[*it].erase(f);
              if (1 == g[*it].size()) {
                tmp.push(*it);
              }
            }
          }
        }
        return result;
    }
};

// 1124ms 71%
