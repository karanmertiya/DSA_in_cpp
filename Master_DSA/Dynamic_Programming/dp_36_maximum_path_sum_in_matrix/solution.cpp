// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Start from bottom row up. `dp[i][j] = matrix[i][j] + max(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1])`. The answer is max value in `dp[0]`.

int maximumPath(int N, vector<vector<int>> Matrix) {
    vector<int> prev(N, 0), curr(N, 0);
    for(int j = 0; j < N; j++) prev[j] = Matrix[N-1][j];
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            int up = Matrix[i][j] + prev[j];
            int ld = Matrix[i][j] + (j > 0 ? prev[j-1] : 0);
            int rd = Matrix[i][j] + (j < N - 1 ? prev[j+1] : 0);
            curr[j] = max({up, ld, rd});
        }
        prev = curr;
    }
    int ans = 0;
    for(int j = 0; j < N; j++) ans = max(ans, prev[j]);
    return ans;
}

