// Time Complexity: O(N * K log K)
// Space Complexity: O(N * K)
// Explanation: Use DP. `dp[i][j]` is the min attempts with `i` eggs and `j` floors. Try dropping from every floor `x` from 1 to `j`. `res = 1 + max(dp[i-1][x-1] (breaks), dp[i][j-x] (doesn't break))`. Optimize this nested loop using Binary Search or use a different state `dp[m][k]` = floors checked with `m` moves and `k` eggs.

int eggDrop(int n, int k) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    int m = 0;
    while(dp[m][n] < k) {
        m++;
        for(int x = 1; x <= n; x++) {
            dp[m][x] = 1 + dp[m-1][x-1] + dp[m-1][x];
        }
    }
    return m;
}

