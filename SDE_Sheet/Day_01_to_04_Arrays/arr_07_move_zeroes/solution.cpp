// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {
    int i = 0;
    for(int j = 0; j < nums.size(); j++) {
        if(nums[j] != 0) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Two-pointer approach (Snowball method). Pointer `i` tracks the first zero found, pointer `j` scans for non-zeroes to swap.

#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {
    int i = 0;
    for(int j = 0; j < nums.size(); j++) {
        if(nums[j] != 0) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }
}

