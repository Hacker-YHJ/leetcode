char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int count = tLen;
    int i = 0, j = 0;
    
    if (0 == sLen || 0 == tLen) return "";
    
    int minLen = 0x7FFFFFFF;
    int minJ = 0;
    bool charSet[256];
    int stats[256];
    
    memset(stats, 0, sizeof(stats));
    memset(charSet, 0, sizeof(charSet));
    
    for (int p = 0; p < tLen; ++p) ++stats[t[p]], charSet[t[p]] = true;
    
    while (i <= sLen && j < sLen) {
        if (!count) {
            if (i-j < minLen) minLen = i-j, minJ = j;
            if (charSet[s[j]]) ++stats[s[j]];
            if (stats[s[j]] > 0) ++count;
            ++j;
        }
        if (count) {
            if(stats[s[i]] > 0) --count;
            if(charSet[s[i]]) --stats[s[i]];
            ++i;
        }
    }
    
    if (0x7FFFFFFF == minLen) return "";
    
    char* toR = (char*)malloc((minLen+1)*sizeof(char));
    memcpy(toR, s+minJ, minLen);
    toR[minLen] = '\0';
    return toR;
}

// 4ms 58%
