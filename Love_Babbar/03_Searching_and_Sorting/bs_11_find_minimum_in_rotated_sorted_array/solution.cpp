// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Optimal: Binary Search. Compare mid with right pointer. If nums[mid] > nums[right], the min is in the right half. Else, the min is in the left half including mid.

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

