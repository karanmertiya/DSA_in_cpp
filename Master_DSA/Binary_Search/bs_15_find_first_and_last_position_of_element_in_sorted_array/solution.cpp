// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Use lower_bound for the first occurrence. Use upper_bound - 1 for the last occurrence. Validate if the target actually exists at the lower_bound index.

vector<int> searchRange(vector<int>& nums, int target) {
    auto lb = lower_bound(nums.begin(), nums.end(), target);
    auto ub = upper_bound(nums.begin(), nums.end(), target);
    if(lb == nums.end() || *lb != target) return {-1, -1};
    return {(int)(lb - nums.begin()), (int)(ub - nums.begin() - 1)};
}

