// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)
// Explanation: Recursive backtracking (include/exclude pattern).

void solve(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[idx]);
    solve(idx + 1, nums, curr, ans);
    curr.pop_back();
    solve(idx + 1, nums, curr, ans);
}
vector<vector<int>> subsetsRec(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(0, nums, curr, ans);
    return ans;
}

// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)
// Explanation: Bit manipulation technique. For N elements, there are 2^N subsets. Count from 0 to 2^N - 1. For each number, its binary representation indicates which elements to include.

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsetsCount = 1 << n;
    vector<vector<int>> ans;
    for(int i=0; i<subsetsCount; i++) {
        vector<int> subset;
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) subset.push_back(nums[j]);
        }
        ans.push_back(subset);
    }
    return ans;
}

