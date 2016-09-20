void dfs(int curr, int n, int arr[], int* result) {
    int tmp;
    bool flag;
    if (curr == n) {
        ++ *result;
        return;
    }
    for (int i = 0; i < n; ++i) {
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
            dfs(curr+1, n, arr, result);
        }
    }  
}

int totalNQueens(int n) {
    int result = 0;
    int arr[n];
    memset(arr, -1, sizeof(arr));
    dfs(0, n, arr, &result);
    return result;
}

// 0ms
