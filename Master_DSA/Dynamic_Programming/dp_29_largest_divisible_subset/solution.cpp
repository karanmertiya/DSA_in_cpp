// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Sort the array. Then use LIS logic: `dp[i]` is max subset ending at `i`. If `nums[i] % nums[j] == 0`, `dp[i] = max(dp[i], dp[j] + 1)`. Also keep a `parent` array to reconstruct the subset.

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if(nums.empty()) return {};
    sort(nums.begin(), nums.end());
    int n = nums.size(), max_len = 1, max_idx = 0;
    vector<int> dp(n, 1), parent(n, -1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }
    vector<int> res;
    while(max_idx != -1) {
        res.push_back(nums[max_idx]);
        max_idx = parent[max_idx];
    }
    return res;
}

