// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: MCM Pattern. Add 1 at the beginning and end. Loop lengths from 1 to N. Iterate start `i` and end `j`. Then iterate `k` from `i` to `j`, meaning balloon `k` is the LAST one to burst in the range `[i, j]`. The coins collected are `nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]`.

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=n; j++) {
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int k=i; k<=j; k++) {
                int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

