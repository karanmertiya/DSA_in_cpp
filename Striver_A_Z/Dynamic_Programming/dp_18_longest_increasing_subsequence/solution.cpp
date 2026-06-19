// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Create a `dp` array of size `n` initialized to 1. For each `i` from 1 to `n-1`, check all `j` from 0 to `i-1`. If `nums[i] > nums[j]`, update `dp[i] = max(dp[i], dp[j] + 1)`. The result is the max in `dp`.

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

