// Time Complexity: O(K^N)
// Space Complexity: O(N)
// Explanation: If total sum is not divisible by K, return false. Create an array of K subset sums. Backtrack to assign each element to one of the K subsets, ensuring no subset sum exceeds total_sum / K. To optimize, sort array descending.

bool solve(int a[], int n, int k, int target, vector<int>& subsetSum, int idx) {
    if(idx == n) {
        for(int i = 0; i < k; i++) if(subsetSum[i] != target) return false;
        return true;
    }
    for(int i = 0; i < k; i++) {
        if(subsetSum[i] + a[idx] <= target) {
            subsetSum[i] += a[idx];
            if(solve(a, n, k, target, subsetSum, idx + 1)) return true;
            subsetSum[i] -= a[idx];
        }
        if(subsetSum[i] == 0) break; // Optimization
    }
    return false;
}
bool isKPartitionPossible(int a[], int n, int k) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    if(sum % k != 0) return false;
    sort(a, a + n, greater<int>());
    vector<int> subsetSum(k, 0);
    return solve(a, n, k, sum / k, subsetSum, 0);
}

