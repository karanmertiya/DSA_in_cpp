// Time Complexity: O(N * K)
// Space Complexity: O(N)
// Explanation: `dp[i]` is max sum for prefix of length `i`. To find `dp[i]`, try all partition lengths `j` from 1 to `k`. Keep track of `max_val` in the last `j` elements. `dp[i] = max(dp[i], dp[i-j] + max_val * j)`.

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int max_val = 0;
        for(int j = 1; j <= k && i - j >= 0; j++) {
            max_val = max(max_val, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + max_val * j);
        }
    }
    return dp[n];
}

