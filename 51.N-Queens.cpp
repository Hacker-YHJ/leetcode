class Solution {
private:
    vector<vector<string>> res;
    int N;

    void dfs(int curr, vector<int> arr) {
        int tmp;
        bool flag;
        if (curr == N) {
            res.push_back(transform(arr));
            return;
        }
        for (int i = 0; i < N; ++i) {
            tmp = i;
            flag = true;
            for (int j = 0; j < curr; ++j) {
                if (tmp == arr[j] || (tmp+curr) == (arr[j]+j) || (tmp-curr) == (arr[j]-j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                arr[curr] = tmp;
                dfs(curr+1, arr);
            }
        }
    }

    vector<string> transform(vector<int> arr) {
        vector<string> res;
        for (int i = 0; i < N; ++i) {
            string line;
            for (int j = 0; j < N; ++j) {
                line += arr[i] == j ? 'Q' : '.';
            }
            res.push_back(line);
        }
        return res;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> arr(n, -1);
        N = n;
        dfs(0, arr);
        return res;
    }

};
