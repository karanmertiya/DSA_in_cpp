// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>

bool check(std::vector<int>& nums) {
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    return count <= 1;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Count the number of "breaks" where `nums[i] > nums[i+1]`. For a sorted and rotated array, there can be at most 1 break.

#include <vector>

bool check(std::vector<int>& nums) {
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    return count <= 1;
}

