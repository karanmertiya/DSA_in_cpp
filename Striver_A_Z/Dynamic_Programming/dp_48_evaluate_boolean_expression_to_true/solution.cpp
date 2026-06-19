// Time Complexity: O(N^3)
// Space Complexity: O(N^2 * 2)
// Explanation: `dp[i][j][isTrue]` is number of ways to evaluate substring `i..j` to boolean `isTrue`. Iterate `k` from `i+1` to `j-1` with step 2 (k is operator). Combine left (`i..k-1`) and right (`k+1..j`) results based on the operator.

int countWays(int n, string s){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int i=0; i<n; i+=2) {
        if(s[i] == 'T') dp[i][i][1] = 1;
        else dp[i][i][0] = 1;
    }
    for(int len=3; len<=n; len+=2) {
        for(int i=0; i<=n-len; i+=2) {
            int j = i + len - 1;
            for(int k=i+1; k<j; k+=2) {
                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];
                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];
                if(s[k] == '&') {
                    dp[i][j][1] = (dp[i][j][1] + lT * rT) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + lF * rT + lT * rF + lF * rF) % 1003;
                } else if(s[k] == '|') {
                    dp[i][j][1] = (dp[i][j][1] + lT * rT + lF * rT + lT * rF) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + lF * rF) % 1003;
                } else if(s[k] == '^') {
                    dp[i][j][1] = (dp[i][j][1] + lT * rF + lF * rT) % 1003;
                    dp[i][j][0] = (dp[i][j][0] + lT * rT + lF * rF) % 1003;
                }
            }
        }
    }
    return dp[0][n-1][1];
}

