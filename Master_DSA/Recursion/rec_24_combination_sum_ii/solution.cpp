// Time Complexity: O(2^N)
// Space Complexity: O(N * X) where X is number of combinations
// Explanation: Sort candidates. Recursively pick combinations. If `i > ind` and `candidates[i] == candidates[i-1]`, skip to avoid duplicates. If `target - candidates[i] >= 0`, pick it.

void findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if(target == 0) {
        ans.push_back(ds);
        return;
    }
    for(int i=ind; i<arr.size(); i++) {
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        findCombinations(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}

