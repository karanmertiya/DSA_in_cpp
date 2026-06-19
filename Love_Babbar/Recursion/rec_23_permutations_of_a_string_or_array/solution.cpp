// Time Complexity: O(N! * N)
// Space Complexity: O(N)
// Explanation: Iterate `i` from `index` to `n-1`. Swap `nums[index]` and `nums[i]`, then recurse for `index + 1`. Swap back to backtrack.

void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if(index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

