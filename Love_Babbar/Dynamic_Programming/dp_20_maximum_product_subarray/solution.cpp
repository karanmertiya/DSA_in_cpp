// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate through the array while maintaining a `currMax` and `currMin`. If `nums[i] < 0`, swap `currMax` and `currMin`. `currMax = max(nums[i], currMax * nums[i])`. `currMin = min(nums[i], currMin * nums[i])`. Update `globalMax`.

int maxProduct(vector<int>& nums) {
    if(nums.empty()) return 0;
    int currMax = nums[0];
    int currMin = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < 0) swap(currMax, currMin);
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);
        ans = max(ans, currMax);
    }
    return ans;
}

