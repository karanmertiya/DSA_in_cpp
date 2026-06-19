// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: Standard MCM DP. `dp[i][j]` is min cost to multiply matrices from `i` to `j`. Iterate length of chain, start `i`, and partition `k`. `dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j])`.

int matrixMultiplication(int N, int arr[]) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for(int i=N-1; i>=1; i--) {
        for(int j=i+1; j<N; j++) {
            int mini = 1e9;
            for(int k=i; k<j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

