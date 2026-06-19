// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: 2D DP. If characters match, `dp[i][j] = 1 + dp[i-1][j-1]`. If they don't, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`. Can be space optimized to two 1D arrays.

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}

