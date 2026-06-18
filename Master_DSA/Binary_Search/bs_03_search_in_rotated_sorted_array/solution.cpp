// Time Complexity: O(log N) (Constraint)
// Space Complexity: O(1)
// Explanation: Identify which half of the array is strictly sorted. Then check if the target lies within that sorted half.

#include <vector>

int searchRotated(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        
        // Left half is sorted
        if(nums[low] <= nums[mid]) {
            if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        } 
        // Right half is sorted
        else {
            if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

