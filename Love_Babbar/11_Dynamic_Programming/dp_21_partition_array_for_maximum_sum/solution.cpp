// Time Complexity: O(N * K)
// Space Complexity: O(N)
// Explanation: Front partitioning. `dp[i]` is max sum for `arr[i..n-1]`. For each `i`, iterate `j` up to `i+k-1`. Find `maxi` element in this window, and add `maxi * length + dp[j+1]`.

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for(int i=n-1; i>=0; i--) {
        int max_val = 0;
        int max_ans = 0;
        int len = 0;
        for(int j=i; j<min(n, i + k); j++) {
            len++;
            max_val = max(max_val, arr[j]);
            int sum = max_val * len + dp[j+1];
            max_ans = max(max_ans, sum);
        }
        dp[i] = max_ans;
    }
    return dp[0];
}

