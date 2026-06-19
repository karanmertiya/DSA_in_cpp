// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: Use DP. `dp[i][j]` stores the size of the maximum square ending at cell `(i, j)`. If `mat[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`.

int maxSquare(int n, int m, vector<vector<int>> mat) {
    vector<int> prev(m, 0), curr(m, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                if(i == 0 || j == 0) curr[j] = 1;
                else curr[j] = min({prev[j], curr[j-1], prev[j-1]}) + 1;
                ans = max(ans, curr[j]);
            } else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

