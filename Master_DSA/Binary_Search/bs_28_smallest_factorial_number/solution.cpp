// Time Complexity: O(log_5(N) * log(5*N))
// Space Complexity: O(1)
// Explanation: Trailing zeros depend on number of 5s. Find count of 5s in `mid!`. Use binary search on the number. Low = 0, high = 5*N. If `check(mid) >= n`, `ans = mid` and `high = mid - 1`. Else `low = mid + 1`.

bool check(int p, int n) {
    int count = 0, temp = p, f = 5;
    while(f <= temp) {
        count += temp / f;
        f *= 5;
    }
    return count >= n;
}
int findNum(int n) {
    if(n == 1) return 5;
    int low = 0, high = 5 * n;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

