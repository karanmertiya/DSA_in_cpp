// Time Complexity: O(log N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Standard Iterative approach. Maintain `low` and `high` boundaries, shrinking the search space by half.

#include <vector>

int search(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

