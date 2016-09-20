bool isInterleave(char* s1, char* s2, char* s3) {
    int s2Len = strlen(s2);
    int s1Len = strlen(s1);
    int s3Len = strlen(s3);
    
    if (s1Len + s2Len != s3Len) return false;
    
    bool arr[s1Len+1];
    bool tmp;
    
    arr[0] = true;
    for (int i = 1; i <= s1Len; ++i) arr[i] = arr[i-1] && s1[i-1] == s3[i-1];

    for (int j = 1; j <= s2Len; ++j) {
        tmp = arr[0];
        arr[0] = arr[0] && s2[j-1] == s3[j-1]; 
        for (int i = 1; i <= s1Len; ++i) {
            tmp = arr[i];
            arr[i] = false;
            if (s1[i-1] == s3[i+j-1]) arr[i] |= arr[i-1];
            if (s2[j-1] == s3[i+j-1]) arr[i] |= tmp;
        }
    }
    
    return arr[s1Len];
}

// 0ms 10%
