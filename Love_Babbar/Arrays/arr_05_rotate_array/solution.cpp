// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Reverse Algorithm. Reverse the whole array, then reverse the first `k` elements, then reverse the remaining `N-k` elements.

#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

