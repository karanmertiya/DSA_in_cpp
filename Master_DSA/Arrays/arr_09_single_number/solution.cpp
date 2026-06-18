// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: XOR property: `A ^ A = 0` and `A ^ 0 = A`. XOR all elements together, duplicates cancel out, leaving only the single element.

#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for(int num : nums) {
        result ^= num;
    }
    return result;
}

