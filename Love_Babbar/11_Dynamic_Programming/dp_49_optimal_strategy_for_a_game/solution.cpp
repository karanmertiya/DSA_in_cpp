// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: If you pick `i`, opponent picks `i+1` or `j`, leaving you with `(i+2, j)` or `(i+1, j-1)`. Opponent plays optimally to minimize your profit. So you get `A[i] + min(dp(i+2, j), dp(i+1, j-1))`. Similarly for picking `j`. Take the max of these two choices.

long long maximumAmount(int arr[], int n) {
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for(int gap = 0; gap < n; gap++) {
        for(int i = 0, j = gap; j < n; i++, j++) {
            long long x = ((i + 2) <= j) ? dp[i+2][j] : 0;
            long long y = ((i + 1) <= (j - 1)) ? dp[i+1][j-1] : 0;
            long long z = (i <= (j - 2)) ? dp[i][j-2] : 0;
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
    return dp[0][n-1];
}

