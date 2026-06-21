// Time Complexity: O(log N) average, O(N) worst case
// Space Complexity: O(1)
// Explanation: Optimal: If `nums[low] == nums[mid] == nums[high]`, shrink the search space by `low++` and `high--`. Otherwise, proceed with the standard rotated binary search.

bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return true;
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++; high--; continue;
        }
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}

