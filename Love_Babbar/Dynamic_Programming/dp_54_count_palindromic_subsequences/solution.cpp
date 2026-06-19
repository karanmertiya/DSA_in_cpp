// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: If `s[i] == s[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. If `s[i] != s[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.

long long int countPS(string str) {
    int n = str.length();
    long long int mod = 1e9 + 7;
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(str[i] == str[j]) {
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % mod;
            } else {
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + mod) % mod;
            }
        }
    }
    return dp[0][n-1];
}

