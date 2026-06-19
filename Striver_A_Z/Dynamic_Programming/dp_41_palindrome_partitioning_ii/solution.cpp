// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: First, precompute a 2D boolean array `isPal[i][j]` to quickly check if `s[i..j]` is a palindrome. Then, use a 1D DP array where `dp[i]` represents the minimum cuts for `s[0..i]`. For each `i`, iterate `j` from `0` to `i`. If `s[j..i]` is a palindrome, then `dp[i] = min(dp[i], dp[j-1] + 1)`. If `s[0..i]` is a palindrome, `dp[i] = 0`.

int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        isPal[i][i] = true;
        if(i < n - 1 && s[i] == s[i+1]) isPal[i][i+1] = true;
    }
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && isPal[i+1][j-1]) isPal[i][j] = true;
        }
    }
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) {
        if(isPal[0][i]) { dp[i] = 0; continue; }
        int minCuts = i;
        for(int j = 1; j <= i; j++) {
            if(isPal[j][i]) minCuts = min(minCuts, dp[j-1] + 1);
        }
        dp[i] = minCuts;
    }
    return dp[n-1];
}

