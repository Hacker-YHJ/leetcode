class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> res = dungeon;
        int rs = res.size();
        int cs = res[0].size();
        res[rs-1][cs-1] = dungeon[rs-1][cs-1] > 0 ? 1 : 1-dungeon[rs-1][cs-1];
        for (int i = rs-2; i >= 0; --i) {
            if (dungeon[i][cs-1] >= 0) res[i][cs-1] = res[i+1][cs-1] - dungeon[i][cs-1] > 0 ? res[i+1][cs-1] - dungeon[i][cs-1] : 1;
            else res[i][cs-1] = res[i+1][cs-1] - dungeon[i][cs-1];
        }
        for (int j = cs-2; j >= 0; --j) {
            if (dungeon[rs-1][j] >= 0) res[rs-1][j] = res[rs-1][j+1] - dungeon[rs-1][j] > 0 ? res[rs-1][j+1] - dungeon[rs-1][j] : 1;
            else res[rs-1][j] = res[rs-1][j+1] - dungeon[rs-1][j];
        }
        for (int i = rs-2; i >= 0; --i) {
            for (int j = cs-2; j >= 0; --j) {
                int min = res[i+1][j] < res[i][j+1] ? res[i+1][j] : res[i][j+1];
                if (dungeon[i][j] > 0) res[i][j] = min - dungeon[i][j] > 0 ? min - dungeon[i][j] : 1;
                else res[i][j] = min - dungeon[i][j];
            }
        }
        // for (int i = 0; i < rs; ++i) {
        //     for (int j = 0; j < cs; ++j) {
        //         cout << res[i][j] << ',';
        //     }
        //     cout << endl;
        // }
        return res[0][0];
    }
};
// 16ms 17%
