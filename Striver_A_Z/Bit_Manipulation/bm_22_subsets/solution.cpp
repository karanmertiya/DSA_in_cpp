// Time Complexity: O(N * 2^N)
// Space Complexity: O(2^N * N)
// Explanation: Iterate from `0` to `2^N - 1`. If the `j`th bit is set in `i`, include `nums[j]` in the current subset.

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsetCount = 1 << n;
    vector<vector<int>> ans;
    for(int i=0; i<subsetCount; i++) {
        vector<int> sub;
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) sub.push_back(nums[j]);
        }
        ans.push_back(sub);
    }
    return ans;
}

