// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use an extra array to place elements at `(i + k) % N`.

#include <vector>

void rotateBrute(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    std::vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Reverse parts of the array: Reverse full array, reverse first `k`, reverse rest.

#include <vector>
#include <algorithm>

void rotateOptimal(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Prevent out of bounds
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

