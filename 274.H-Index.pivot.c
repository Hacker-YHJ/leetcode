void swap(int* a, int* b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int pivot(int* citations, int s, int e) {
    int p = s, c = s;
    
    if (s == e) return s;
    
    // randomly select pivot
    swap(citations+s+rand()%(e-s+1), citations+e);
    for (p = s; p < e; ++p) if (citations[p] <= citations[e]) swap(citations+(c++), citations+p);
    swap(citations+c, citations+e);
    return c;
}

int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 0) return 0;
    int s = 0, e = citationsSize-1, h = 0, c;
    while(s <= e) {
        c = pivot(citations, s, e);
        if (citations[c] >= citationsSize-c) (h = citationsSize-c, e = c-1);
        else s = c+1;
    }
    return h;
}

// 0ms
// 100%
