// Time Complexity: O(N * K) or O(N)
// Space Complexity: O(1) or O(N)
// Explanation: Brute Force: Rotate the array one by one, k times. Or use a temporary array of size N.

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    for(int i=0; i<n; i++) {
        temp[(i+k)%n] = nums[i];
    }
    nums = temp;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Reverse Algorithm. Reverse the whole array, then reverse the first `k` elements, then reverse the remaining `N-k` elements.

#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

