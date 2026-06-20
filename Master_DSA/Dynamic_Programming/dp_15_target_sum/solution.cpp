// Time Complexity: O(N * Target)
// Space Complexity: O(Target)
// Explanation: Subset sum variation. `S1 - S2 = target`, `S1 + S2 = totalSum`. So, `S1 = (target + totalSum) / 2`. Find subsets with this target sum.

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0; for(int n : nums) sum += n;
    if(sum - target < 0 || (sum - target) % 2 == 1) return 0;
    int s2 = (sum - target) / 2;
    vector<int> prev(s2 + 1, 0);
    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(nums[0] != 0 && nums[0] <= s2) prev[nums[0]] = 1;
    for(int ind=1; ind<nums.size(); ind++) {
        vector<int> cur(s2 + 1, 0);
        for(int t=0; t<=s2; t++) {
            int notTaken = prev[t];
            int taken = 0;
            if(nums[ind] <= t) taken = prev[t - nums[ind]];
            cur[t] = notTaken + taken;
        }
        prev = cur;
    }
    return prev[s2];
}

