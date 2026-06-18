// Time Complexity: O(2<sup>N</sup>) (Constraint)
// Space Complexity: O(N) (Constraint)
// Explanation: Pick / Non-Pick logic. For every element, we have two choices: either include it in the current subset, or don't. Recursively explore both paths.

#include <vector>

void solve(int i, std::vector<int>& nums, std::vector<int>& temp, std::vector<std::vector<int>>& ans) {
    if (i == nums.size()) {
        ans.push_back(temp);
        return;
    }
    // Pick
    temp.push_back(nums[i]);
    solve(i + 1, nums, temp, ans);
    temp.pop_back();
    
    // Not Pick
    solve(i + 1, nums, temp, ans);
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    solve(0, nums, temp, ans);
    return ans;
}

