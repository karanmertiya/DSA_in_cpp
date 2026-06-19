// Time Complexity: O(N * M)
// Space Complexity: O(N * M) or O(M)
// Explanation: Use a 2D DP array where `dp[i][j]` means if `s[0..i-1]` matches `p[0..j-1]`. If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, `dp[i][j] = dp[i-1][j-1]`. If `p[j-1] == '*'`, it can match empty (`dp[i][j-1]`) or match one character (`dp[i-1][j]`).

bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for(int j = 1; j <= m; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == s[i-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

