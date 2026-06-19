// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: Use DP where `dp[i][j]` is min cost to multiply matrices from `i` to `j`. `dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j])` for all `i <= k < j`. Solve for subproblem lengths 2 to N.

int matrixMultiplication(int N, int arr[]) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for(int len = 2; len < N; len++) {
        for(int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][N-1];
}

