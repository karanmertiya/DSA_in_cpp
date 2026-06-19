// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: If characters match, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`. If they don't, `dp[i][j] = dp[i-1][j]`. Optimize to 1D array.

int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    vector<double> dp(m + 1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=1; j--) {
            if(s[i-1] == t[j-1]) {
                dp[j] = dp[j-1] + dp[j];
            }
        }
    }
    return (int)dp[m];
}

