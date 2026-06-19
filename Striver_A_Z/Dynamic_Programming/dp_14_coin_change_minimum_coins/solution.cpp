// Time Complexity: O(amount * N)
// Space Complexity: O(amount)
// Explanation: Create an array `dp` of size `amount + 1` initialized to `amount + 1` (acting as infinity). `dp[0] = 0`. For each amount from 1 to `amount`, for each coin, if `i - coin >= 0`, `dp[i] = min(dp[i], dp[i - coin] + 1)`.

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

