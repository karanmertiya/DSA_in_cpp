// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a min-heap storing `(value, list_idx, elem_idx)`. Also maintain the `current_max` of the elements currently in the heap. The current range is `[heap_top, current_max]`. Pop the min, push the next element from its list, and update `current_max`. Continue until any list is exhausted.

vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int currMax = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        pq.push({nums[i][0], i, 0});
        currMax = max(currMax, nums[i][0]);
    }
    vector<int> ans = {pq.top()[0], currMax};
    while(true) {
        auto curr = pq.top(); pq.pop();
        int val = curr[0], r = curr[1], c = curr[2];
        if(currMax - val < ans[1] - ans[0]) {
            ans = {val, currMax};
        }
        if(c + 1 == nums[r].size()) break;
        pq.push({nums[r][c + 1], r, c + 1});
        currMax = max(currMax, nums[r][c + 1]);
    }
    return ans;
}

