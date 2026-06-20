// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Use Dynamic Programming. `dp[i]` represents the minimum cost to wrap words from index `i` to the end. Iterate backward and try placing different numbers of words on the current line.

int solveWordWrap(vector<int>nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        int currlen = -1;
        dp[i] = INT_MAX;
        for(int j = i; j < n; j++) {
            currlen += (nums[j] + 1);
            if(currlen > k) break;
            if(j == n - 1) dp[i] = 0;
            else {
                int cost = (k - currlen) * (k - currlen) + dp[j + 1];
                dp[i] = min(dp[i], cost);
            }
        }
    }
    return dp[0];
}

