// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: MCM DP. `dp[i][j][isTrue]` stores the number of ways to evaluate `S[i..j]` to boolean `isTrue`. Iterate length, start, and partition `k`. Calculate T/F ways based on the operator at `k`.

int countWays(int N, string S){
    int mod = 1003;
    vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, 0)));
    for(int i=N-1; i>=0; i-=2) {
        for(int j=i; j<N; j+=2) {
            if(i == j) {
                dp[i][j][1] = (S[i] == 'T');
                dp[i][j][0] = (S[i] == 'F');
                continue;
            }
            long long waysT = 0, waysF = 0;
            for(int k=i+1; k<=j-1; k+=2) {
                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];
                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];
                if(S[k] == '&') {
                    waysT = (waysT + (lT * rT) % mod) % mod;
                    waysF = (waysF + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                } else if(S[k] == '|') {
                    waysT = (waysT + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    waysF = (waysF + (lF * rF) % mod) % mod;
                } else if(S[k] == '^') {
                    waysT = (waysT + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    waysF = (waysF + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
            dp[i][j][1] = waysT;
            dp[i][j][0] = waysF;
        }
    }
    return dp[0][N-1][1];
}

