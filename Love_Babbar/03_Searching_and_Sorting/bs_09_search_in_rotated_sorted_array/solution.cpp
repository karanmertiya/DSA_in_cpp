// Time Complexity: O(log N) (Constraint)
// Space Complexity: O(1)
// Explanation: Optimal: Identify the sorted half. Check if target lies within the boundaries of the sorted half. If yes, shrink to that half; else, shrink to the other.

#include <vector>

int search(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        
        // Left half sorted
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        } 
        // Right half sorted
        else {
            if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

