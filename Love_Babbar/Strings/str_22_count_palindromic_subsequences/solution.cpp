// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Use DP. `dp[i][j]` stores the count of palindromic subsequences in `str[i..j]`. If `str[i] == str[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. Else, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.

long long int countPS(string str) {
    long long int MOD = 1e9 + 7;
    int n = str.length();
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(str[i] == str[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;
            else dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD;
        }
    }
    return dp[0][n - 1];
}

