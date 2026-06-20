// Time Complexity: O(M * N)
// Space Complexity: O(M * N)
// Explanation: Build the LCS DP table. Start from `dp[m][n]`. If `s1[i-1] == s2[j-1]`, include this character in the result and move diagonally to `dp[i-1][j-1]`. Otherwise, move to the maximum of `dp[i-1][j]` or `dp[i][j-1]`. Reverse the string at the end.

string printLCS(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = m, j = n;
    string res = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            res += s1[i-1];
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(res.begin(), res.end());
    return res;
}

