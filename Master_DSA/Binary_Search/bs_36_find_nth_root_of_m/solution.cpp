// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int func(int mid, int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int NthRoot(int n, int m) {
    int low = 1, high = m;
    while(low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Time Complexity: O(N * log M)
// Space Complexity: O(1)
// Explanation: Optimal: Search space is `[1, m]`. Check `mid^n`. Since `mid^n` can overflow, use a custom power function that returns 1 if `mid^n == m`, 0 if `< m`, and 2 if `> m`. Adjust `low` and `high` accordingly.

int func(int mid, int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int NthRoot(int n, int m) {
    int low = 1, high = m;
    while(low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

