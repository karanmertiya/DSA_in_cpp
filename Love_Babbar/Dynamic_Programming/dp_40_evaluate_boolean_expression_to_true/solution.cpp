// Time Complexity: O(N^3)
// Space Complexity: O(N^2 * 2)
// Explanation: MCM variant. `dp[i][j][isTrue]` stores the number of ways to evaluate the expression from `i` to `j` to `isTrue`. Partition at every operator `k`. Calculate `leftTrue`, `leftFalse`, `rightTrue`, `rightFalse`. Combine these based on the operator `S[k]`.

int solve(string S, int i, int j, int isTrue, vector<vector<vector<int>>>& dp) {
    if(i > j) return 0;
    if(i == j) {
        if(isTrue == 1) return S[i] == 'T';
        else return S[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    long long ways = 0;
    int mod = 1003;
    for(int k = i + 1; k <= j - 1; k += 2) {
        long long lT = solve(S, i, k - 1, 1, dp);
        long long lF = solve(S, i, k - 1, 0, dp);
        long long rT = solve(S, k + 1, j, 1, dp);
        long long rF = solve(S, k + 1, j, 0, dp);
        if(S[k] == '&') {
            if(isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        } else if(S[k] == '|') {
            if(isTrue) ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        } else if(S[k] == '^') {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int countWays(int N, string S) {
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
    return solve(S, 0, N - 1, 1, dp);
}

