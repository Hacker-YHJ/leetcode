int largestRectangleArea(int* height, int heightSize) {
    int result = 0,size = heightSize, hi;
    int ascending[heightSize], index = -1;

    for (int i = 0; i <= size; i++) {
        hi = size == i ? 0 : height[i];
        while (index >= 0 && height[ascending[index]] >= hi) {
            int th = height[ascending[index]];
            int left = -1;
            
            left = --index >= 0 ? ascending[index] : left;
            result = (th * (i - left - 1) > result) ? th * (i - left - 1) : result;
        }
        ascending[++index] = i;
    }

    return result;
}

// 8ms
