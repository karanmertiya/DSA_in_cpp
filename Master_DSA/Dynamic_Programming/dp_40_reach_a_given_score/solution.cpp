// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: `dp[i]` represents number of ways to reach score `i`. Init `dp[0] = 1`. For each score option (3, 5, 10), iterate from option to `n`, `dp[i] += dp[i - option]`.

long long int count(long long int n) {
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> scores = {3, 5, 10};
    for(int s : scores) {
        for(int i = s; i <= n; i++) {
            dp[i] += dp[i - s];
        }
    }
    return dp[n];
}

