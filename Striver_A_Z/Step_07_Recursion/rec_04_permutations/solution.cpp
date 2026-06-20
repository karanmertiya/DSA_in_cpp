// Time Complexity: O(N! * N)
// Space Complexity: O(N)
// Explanation: Backtracking. Swap elements to generate permutations. For index `i`, swap it with every index from `i` to `n-1`, recurse, then backtrack (swap back).

#include <vector>
#include <algorithm>
void solve(int idx, std::vector<int>& nums, std::vector<std::vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = idx; i < nums.size(); i++) {
        std::swap(nums[idx], nums[i]);
        solve(idx + 1, nums, ans);
        std::swap(nums[idx], nums[i]);
    }
}
std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}

