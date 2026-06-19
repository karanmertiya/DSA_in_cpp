// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Binary Search. Identify which half is sorted. If left half is sorted and target is in its range, move `high = mid - 1`, else `low = mid + 1`. Symmetrically for right half.

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

