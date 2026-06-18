// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.

#include <vector>

int missingNumber(std::vector<int>& nums) {
    int res = nums.size();
    for(int i = 0; i < nums.size(); i++) {
        res ^= i ^ nums[i];
    }
    return res;
}

