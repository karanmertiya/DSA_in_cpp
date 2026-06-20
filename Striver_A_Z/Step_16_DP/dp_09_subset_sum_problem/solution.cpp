// Time Complexity: O(N * Sum)
// Space Complexity: O(Sum) space optimized
// Explanation: DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.

bool isSubsetSum(vector<int>arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum+1, false), cur(sum+1, false);
    prev[0] = cur[0] = true;
    if(arr[0] <= sum) prev[arr[0]] = true;
    for(int ind=1; ind<n; ind++) {
        for(int target=1; target<=sum; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            if(arr[ind] <= target) taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    return prev[sum];
}

