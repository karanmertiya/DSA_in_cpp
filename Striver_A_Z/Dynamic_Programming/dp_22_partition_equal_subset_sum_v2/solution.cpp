// Time Complexity: O(N * Target)
// Space Complexity: O(Target)
// Explanation: If total sum is odd, it's impossible. Otherwise, target is `sum / 2`. The problem reduces to subset sum. Use a boolean `dp` array of size `target + 1`. `dp[j] = dp[j] || dp[j - num]`.

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int num : nums) sum += num;
    if(sum % 2 != 0) return false;
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for(int num : nums) {
        for(int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

