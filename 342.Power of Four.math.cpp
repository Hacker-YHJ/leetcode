class Solution {
public:
    bool isPowerOfFour(int num) {
        unsigned int uCount = num-1;
        uCount = uCount - ((uCount >> 1) & 033333333333) - ((uCount >> 2) & 011111111111);
        uCount = ((uCount + (uCount >> 3)) & 030707070707) % 63;
        return num && !(num & (num-1)) && !(uCount % 2);
    }
};

// 4ms
