// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Binary Search. If `nums[mid] > nums[mid + 1]`, we are on a descending slope, so a peak must be to the left (or is `mid`). Else, we are on an ascending slope, peak is to the right.

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[mid + 1]) high = mid;
        else low = mid + 1;
    }
    return low;
}

