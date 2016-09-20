bool isMatch(char* s, char* p) {
    int slen = strlen(s), plen = strlen(p);
    bool f[slen+1][plen+1];
    for (int i = 0; i <= slen; ++i) for (int j = 0; j <= plen; ++j) f[i][j] = false;
    f[0][0] = true;
    
    for (int j = 1; j <= plen; j++)
        f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

    for (int i = 1; i <= slen; i++)
        for (int j = 1; j <= plen; j++) {
            if (p[j - 1] != '*')
                f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
            else
                f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
        }

    return f[slen][plen];
    
}

// 4ms
