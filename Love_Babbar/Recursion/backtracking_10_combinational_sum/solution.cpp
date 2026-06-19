// Time Complexity: O(2^N * K)
// Space Complexity: O(K * X)
// Explanation: Sort the array and remove duplicates. Use backtracking. At each step, either include the current element (and stay at the current element to allow unlimited picks) or move to the next element. Backtrack when sum < 0 or we reach the end.

void solve(vector<int>& arr, int sum, int idx, vector<int>& curr, vector<vector<int>>& ans) {
    if(sum == 0) {
        ans.push_back(curr);
        return;
    }
    if(sum < 0 || idx == arr.size()) return;
    curr.push_back(arr[idx]);
    solve(arr, sum - arr[idx], idx, curr, ans);
    curr.pop_back();
    solve(arr, sum, idx + 1, curr, ans);
}
vector<vector<int>> combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int>> ans;
    vector<int> curr;
    solve(A, B, 0, curr, ans);
    return ans;
}

