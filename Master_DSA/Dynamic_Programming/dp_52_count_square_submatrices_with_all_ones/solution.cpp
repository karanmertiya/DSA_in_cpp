// Time Complexity: O(R * C)
// Space Complexity: O(R * C) or O(C) optimized
// Explanation: `dp[i][j]` represents the side length of the maximum square whose bottom-right corner is at `(i, j)`. If `matrix[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. The number of squares ending here is exactly `dp[i][j]`. Sum all `dp[i][j]`.

int countSquares(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    int ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 1) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

