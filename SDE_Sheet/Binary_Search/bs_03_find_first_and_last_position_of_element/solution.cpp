// Time Complexity: O(log N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Run Binary Search twice. Once to find the first occurrence (bias left), once to find the last occurrence (bias right).

#include <vector>

int findBound(std::vector<int>& nums, int target, bool isFirst) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            ans = mid;
            if(isFirst) high = mid - 1;
            else low = mid + 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    return {findBound(nums, target, true), findBound(nums, target, false)};
}

