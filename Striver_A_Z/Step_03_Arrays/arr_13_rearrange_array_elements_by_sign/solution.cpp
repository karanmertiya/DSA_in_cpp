// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Constraint)
// Explanation: Optimal: Use two pointers, `pos_idx` starting at 0, `neg_idx` starting at 1. Traverse and place elements directly into a new result array.

#include <vector>

std::vector<int> rearrangeArray(std::vector<int>& nums) {
    std::vector<int> ans(nums.size());
    int pos_idx = 0, neg_idx = 1;
    for (int num : nums) {
        if (num > 0) {
            ans[pos_idx] = num;
            pos_idx += 2;
        } else {
            ans[neg_idx] = num;
            neg_idx += 2;
        }
    }
    return ans;
}

