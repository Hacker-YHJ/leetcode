class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        set<pair<int, pair<int, int> > > noWater;
        int width = heightMap.size();
        int height = heightMap[0].size();
        int res = 0;
        vector<vector<bool> > flag(width, vector<bool>(height, false));
        for (int i = 0; i < width; ++i) {
            noWater.insert(make_pair(heightMap[i][0], make_pair(i, 0)));
            flag[i][0] = true;
            noWater.insert(make_pair(heightMap[i][height-1], make_pair(i, height-1)));
            flag[i][height-1] = true;
        }
        for (int i = 0; i < height; ++i) {
            noWater.insert(make_pair(heightMap[0][i], make_pair(0, i)));
            flag[0][i] = true;
            noWater.insert(make_pair(heightMap[width-1][i], make_pair(width-1, i)));
            flag[width-1][i] = true;
        }
        while (!noWater.empty()) {
            auto p = *noWater.begin();
            noWater.erase(noWater.begin());
            cout << p.first << ' ' << p.second.first << ',' << p.second.second << endl;
            if (p.second.first > 0 && !flag[p.second.first - 1][p.second.second]) {
                if (p.first > heightMap[p.second.first - 1][p.second.second]) {
                    res += p.first - heightMap[p.second.first - 1][p.second.second];
                    heightMap[p.second.first - 1][p.second.second] = p.first;
                }
                noWater.insert(make_pair(heightMap[p.second.first - 1][p.second.second], make_pair(p.second.first - 1, p.second.second)));
                flag[p.second.first - 1][p.second.second] = true;

            }
            if (p.second.first < width - 1 && !flag[p.second.first + 1][p.second.second]) {
                if (p.first > heightMap[p.second.first + 1][p.second.second]) {
                    res += p.first - heightMap[p.second.first + 1][p.second.second];
                    heightMap[p.second.first + 1][p.second.second] = p.first;
                }
                noWater.insert(make_pair(heightMap[p.second.first + 1][p.second.second], make_pair(p.second.first + 1, p.second.second)));
                flag[p.second.first + 1][p.second.second] = true;

            }
            if (p.second.second > 0 && !flag[p.second.first][p.second.second - 1]) {
                if (p.first > heightMap[p.second.first][p.second.second - 1]) {
                    res += p.first - heightMap[p.second.first][p.second.second - 1];
                    heightMap[p.second.first][p.second.second - 1] = p.first;
                }
                noWater.insert(make_pair(heightMap[p.second.first][p.second.second - 1], make_pair(p.second.first, p.second.second - 1)));
                flag[p.second.first][p.second.second - 1] = true;
            }
            if (p.second.second < height - 1 && !flag[p.second.first][p.second.second + 1]) {
                if (p.first > heightMap[p.second.first][p.second.second + 1]) {
                    res += p.first - heightMap[p.second.first][p.second.second + 1];
                    heightMap[p.second.first][p.second.second + 1] = p.first;
                }
                noWater.insert(make_pair(heightMap[p.second.first][p.second.second + 1], make_pair(p.second.first, p.second.second + 1)));
                flag[p.second.first][p.second.second + 1] = true;
            }
        }
        return res;
    }
};
