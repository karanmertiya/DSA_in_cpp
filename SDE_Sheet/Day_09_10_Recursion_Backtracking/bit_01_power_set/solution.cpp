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

