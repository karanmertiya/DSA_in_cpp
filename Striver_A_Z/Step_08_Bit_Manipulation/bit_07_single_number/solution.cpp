// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Hash Map to count occurrences. Return the element with count 1.

#include <vector>

int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    for(int num : nums) {
        ans ^= num;
    }
    return ans;
}

