// Time Complexity: O(2^9)
// Space Complexity: O(k)
// Explanation: Backtracking. Start from 1, go up to 9. Add the current number to the path and subtract from target. Stop when path size is `k` and `target` is 0.

void solve(int start, int k, int n, vector<int>& ds, vector<vector<int>>& ans) {
    if(k == 0 && n == 0) { ans.push_back(ds); return; }
    if(k == 0 || n < 0) return;
    for(int i = start; i <= 9; i++) {
        ds.push_back(i);
        solve(i + 1, k - 1, n - i, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    solve(1, k, n, ds, ans);
    return ans;
}

