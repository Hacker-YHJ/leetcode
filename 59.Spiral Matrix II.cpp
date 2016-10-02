typedef pair<int, int> Cood;
typedef vector<vector<int> > Matrix;
class Solution {
private:
    int count;
    int tB;
    int bB;
    int lB;
    int rB;
    int direction;
    Cood curr;
public:
    void init(int n) {
        count = n*n;
        tB = 1;
        bB = n - 1;
        lB = 0;
        rB = n - 1;
        direction = 0;
        curr = {0, 0};
    }

    Matrix generateMatrix(int n) {
        init(n);
        if (n == 0) return {};
        Matrix res(n, vector<int>(n));
        for (int i = 1; i <= count; ++i) {
            res[curr.first][curr.second] = i;
            next();
        }
        return res;
    }
    void next() {
        switch (direction) {
            case 0:
                if (curr.second == rB) {
                    direction = 1;
                    --rB;
                    next();
                } else {
                    ++curr.second;
                }
                break;
            case 1:
                if (curr.first == bB) {
                    direction = 2;
                    --bB;
                    next();
                } else {
                    ++curr.first;
                }
                break;
            case 2:
                if (curr.second == lB) {
                    direction = 3;
                    ++lB;
                    next();
                } else {
                    --curr.second;
                }
                break;
            case 3:
                if (curr.first == tB) {
                    direction = 0;
                    ++tB;
                    next();
                } else {
                    --curr.first;
                }
                break;
        }
    }
};
