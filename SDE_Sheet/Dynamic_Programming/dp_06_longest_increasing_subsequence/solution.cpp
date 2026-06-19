// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Create a dp array where dp[i] is the length of LIS ending at index i. For each i, check all j < i to see if nums[i] > nums[j] and update dp[i] = max(dp[i], dp[j] + 1). O(N log N) patience sorting approach is better but standard DP is O(N^2).

int lengthOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for(int i = 1; i < nums.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
        }
        res = std::max(res, dp[i]);
    }
    return res;
}

