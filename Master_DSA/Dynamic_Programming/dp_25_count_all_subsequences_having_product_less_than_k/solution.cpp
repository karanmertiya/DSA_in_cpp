// Time Complexity: O(N * K)
// Space Complexity: O(N * K)
// Explanation: Use a 2D DP array where `dp[i][j]` is the number of subsequences of first `i` elements with product less than or equal to `j`. `dp[i][j] = dp[i-1][j] + dp[i-1][j/arr[i-1]] + 1`.

int countSubsequences(vector<int>& a, int k) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if(a[i - 1] <= j && a[i - 1] > 0) {
                dp[i][j] += dp[i - 1][j / a[i - 1]] + 1;
            }
        }
    }
    return dp[n][k];
}

