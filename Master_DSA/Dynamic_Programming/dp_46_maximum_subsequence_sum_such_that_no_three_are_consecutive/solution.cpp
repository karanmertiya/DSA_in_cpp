// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a DP array. `dp[i]` is the max sum considering up to index `i`. For `i`, the max sum is `max(dp[i-1] (exclude i), dp[i-2] + arr[i] (exclude i-1), dp[i-3] + arr[i] + arr[i-1] (exclude i-2))`.

int maxSum(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return arr[0] + arr[1];
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({dp[1], arr[0] + arr[2], arr[1] + arr[2]});
    for(int i = 3; i < n; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]});
    }
    return dp[n-1];
}

