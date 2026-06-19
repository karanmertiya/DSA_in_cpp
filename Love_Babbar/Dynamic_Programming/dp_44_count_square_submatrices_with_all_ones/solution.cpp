// Time Complexity: O(R * C)
// Space Complexity: O(R * C)
// Explanation: Let `dp[i][j]` be the size of the largest square ending at `(i, j)`. If `matrix[i][j] == 1`, then `dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})`. The total number of squares is the sum of all elements in the `dp` matrix.

int countSquares(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    int ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 1) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

