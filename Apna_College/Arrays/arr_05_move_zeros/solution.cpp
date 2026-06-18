// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Two-pointer approach. Swap non-zero elements with the `zero_pointer`.

#include <vector>
#include <utility>

void moveZeroes(std::vector<int>& nums) {
    int zero_idx = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            std::swap(nums[zero_idx], nums[i]);
            zero_idx++;
        }
    }
}

