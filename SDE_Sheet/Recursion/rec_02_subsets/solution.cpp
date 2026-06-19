// Time Complexity: O(2<sup>N</sup> * N)
// Space Complexity: O(N)
// Explanation: Pick / Not Pick technique. For every element, branch recursively: one path includes the element, the other path excludes it.

#include <vector>
void solve(int idx, std::vector<int>& nums, std::vector<int>& temp, std::vector<std::vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    solve(idx + 1, nums, temp, ans);
    temp.pop_back();
    solve(idx + 1, nums, temp, ans);
}
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    solve(0, nums, temp, ans);
    return ans;
}

