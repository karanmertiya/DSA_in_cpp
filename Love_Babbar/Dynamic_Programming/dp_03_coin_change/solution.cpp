// Time Complexity: O(Amount * N)
// Space Complexity: O(Amount)
// Explanation: Unbounded Knapsack. State `dp[i]` is the min coins needed to make amount `i`. `dp[i] = min(dp[i], 1 + dp[i - coin])`.

#include <vector>
#include <algorithm>
int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(i - coin >= 0) {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

