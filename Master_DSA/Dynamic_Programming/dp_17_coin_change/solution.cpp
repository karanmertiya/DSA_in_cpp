// Time Complexity: O(N * Amount)
// Space Complexity: O(Amount)
// Explanation: Unbounded Knapsack variant. State `dp[amount]` stores min coins. Iterate through coins, and for each amount from `coin` to `target`, `dp[amt] = min(dp[amt], 1 + dp[amt - coin])`.

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for(int i=0; i<coins.size(); i++) {
        for(int amt=coins[i]; amt<=amount; amt++) {
            dp[amt] = min(dp[amt], 1 + dp[amt - coins[i]]);
        }
    }
    return dp[amount] >= 1e9 ? -1 : dp[amount];
}

