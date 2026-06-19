// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Binary Search. If `nums[low] <= nums[high]`, the array is sorted, return `nums[low]`. Else, if `nums[low] <= nums[mid]`, the left half is sorted, the minimum is in the right half.

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[low] <= nums[high]) { ans = min(ans, nums[low]); break; }
        if(nums[low] <= nums[mid]) { ans = min(ans, nums[low]); low = mid + 1; }
        else { ans = min(ans, nums[mid]); high = mid - 1; }
    }
    return ans;
}

