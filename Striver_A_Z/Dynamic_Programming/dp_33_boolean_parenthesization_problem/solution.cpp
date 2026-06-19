// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: Use a 3D DP array `dp[i][j][isTrue]` representing the number of ways to evaluate the substring from `i` to `j` to `isTrue`. Iterate over all possible split points `k` with an operator. Combine the True and False counts from left and right halves based on the operator.

int countWays(int N, string S) {
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, 0)));
    for(int i = 0; i < N; i += 2) {
        dp[i][i][1] = (S[i] == 'T');
        dp[i][i][0] = (S[i] == 'F');
    }
    for(int len = 3; len <= N; len += 2) {
        for(int i = 0; i <= N - len; i += 2) {
            int j = i + len - 1;
            for(int k = i + 1; k < j; k += 2) {
                int lt = dp[i][k-1][1], lf = dp[i][k-1][0];
                int rt = dp[k+1][j][1], rf = dp[k+1][j][0];
                if(S[k] == '&') {
                    dp[i][j][1] = (dp[i][j][1] + (lt * rt) % 1003) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + (lt * rf) % 1003 + (lf * rt) % 1003 + (lf * rf) % 1003) % 1003;
                } else if(S[k] == '|') {
                    dp[i][j][1] = (dp[i][j][1] + (lt * rt) % 1003 + (lt * rf) % 1003 + (lf * rt) % 1003) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + (lf * rf) % 1003) % 1003;
                } else if(S[k] == '^') {
                    dp[i][j][1] = (dp[i][j][1] + (lt * rf) % 1003 + (lf * rt) % 1003) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + (lt * rt) % 1003 + (lf * rf) % 1003) % 1003;
                }
            }
        }
    }
    return dp[0][N-1][1];
}

