// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Explanation: DP state `dp[i][j]` is true if `s[0..i-1]` matches `p[0..j-1]`. Base cases: empty pattern only matches empty string. `p[0..j-1]` can match empty string if all chars are '*'. Transitions: If `s[i-1] == p[j-1]` or `p[j-1] == '?'`, `dp[i][j] = dp[i-1][j-1]`. If `p[j-1] == '*'`, it can match empty string (`dp[i][j-1]`) or one/more characters (`dp[i-1][j]`).

bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '?' || s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }
    return dp[m][n];
}

