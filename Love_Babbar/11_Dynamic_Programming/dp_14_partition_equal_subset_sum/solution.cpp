// Time Complexity: O(N * Target)
// Space Complexity: O(Target)
// Explanation: If total sum is odd, impossible. Else, find if there's a subset with sum `Total/2` using space-optimized DP.

bool canPartition(vector<int>& nums) {
    int sum = 0; for(int n : nums) sum += n;
    if(sum % 2 != 0) return false;
    int target = sum / 2;
    vector<bool> prev(target + 1, false);
    prev[0] = true;
    if(nums[0] <= target) prev[nums[0]] = true;
    for(int ind=1; ind<nums.size(); ind++) {
        vector<bool> cur(target + 1, false);
        cur[0] = true;
        for(int t=1; t<=target; t++) {
            bool notTaken = prev[t];
            bool taken = false;
            if(nums[ind] <= t) taken = prev[t - nums[ind]];
            cur[t] = notTaken || taken;
        }
        prev = cur;
    }
    return prev[target];
}

