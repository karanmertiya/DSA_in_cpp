// Time Complexity: O(K * 2^N)
// Space Complexity: O(N)
// Explanation: If total sum is not divisible by K, return false. Sort array in descending order. Use a boolean array `vis`. Helper function `solve(ind, currentSum, k)`: if `k == 1` return true. If `currentSum == target`, `solve(0, 0, k-1)`. Otherwise, iterate from `ind` to `N`, if `!vis[i]` and `currentSum + arr[i] <= target`, mark `vis[i] = true`, recurse, unmark.

bool solve(int a[], int n, int k, int target, int currSum, int ind, vector<bool>& vis) {
    if(k == 1) return true;
    if(currSum == target) return solve(a, n, k - 1, target, 0, 0, vis);
    for(int i = ind; i < n; i++) {
        if(!vis[i] && currSum + a[i] <= target) {
            vis[i] = true;
            if(solve(a, n, k, target, currSum + a[i], i + 1, vis)) return true;
            vis[i] = false;
        }
    }
    return false;
}
bool isKPartitionPossible(int a[], int n, int k) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    if(sum % k != 0 || n < k) return false;
    vector<bool> vis(n, false);
    return solve(a, n, k, sum / k, 0, 0, vis);
}

