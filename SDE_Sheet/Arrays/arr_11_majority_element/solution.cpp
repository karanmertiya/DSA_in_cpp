// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.

#include <vector>

int majorityElement(std::vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        if (num == candidate) count++;
        else count--;
    }
    return candidate;
}

