// Time Complexity: O(N * M)
// Space Complexity: O(N * M) or O(M)
// Explanation: `dp[i][j]` is side of max square ending at `(i, j)`. If `mat[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. Result is max over all `dp[i][j]`.

int maxSquare(int n, int m, vector<vector<int>> mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

