class Solution {
public:
    int integerBreak(int n) {
        if (n > 6) {
            int threes = (n - 4)/3;
            return (int)pow(3, threes) * integerBreak(n - threes*3);   
        }
        else if (n == 6) return 9;
        else if (n == 5) return 6;
        else if (n == 4) return 4;
        else if (n == 3) return 2;
        else return 1;
    }
};

// 0ms
