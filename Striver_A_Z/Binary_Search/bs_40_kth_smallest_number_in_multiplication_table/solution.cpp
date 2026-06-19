// Time Complexity: O(m * log(m*n))
// Space Complexity: O(1)
// Explanation: Binary search on range `[1, m*n]`. For a value `mid`, the number of elements `<= mid` in row `i` is `min(mid / i, n)`. Sum this for all rows to get total count. If count >= k, search left. Else search right.

int findKthNumber(int m, int n, int k) {
    int low = 1, high = m * n;
    while(low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int i=1; i<=m; i++) {
            count += min(mid / i, n);
        }
        if(count >= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

