// Time Complexity: O(M * N)
// Space Complexity: O(N)
// Explanation: Create a `dp` array of size `N + 1` initialized to 0. `dp[0] = 1`. For each coin, iterate through all amounts from `coin` to `N` and update `dp[j] += dp[j - coin]`.

long long int count(int coins[], int N, int sum) {
    vector<long long int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[sum];
}

