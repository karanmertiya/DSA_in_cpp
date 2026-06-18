// Time Complexity: O(log N) (Constraint)
// Space Complexity: O(1)
// Explanation: Perform two separate binary searches: one for the first occurrence (bias left) and one for the last (bias right).

#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    auto findBound = [&](bool isFirst) {
        int low = 0, high = nums.size() - 1, res = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                res = mid;
                if(isFirst) high = mid - 1; // Bias Left
                else low = mid + 1;         // Bias Right
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return res;
    };
    return {findBound(true), findBound(false)};
}

