// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Use a 1D DP array `dp` where `dp[i]` is the length of the longest subsequence ending at `i`. For each `i`, check all `j < i`. If `abs(A[i] - A[j]) == 1`, update `dp[i] = max(dp[i], dp[j] + 1)`.

int longestSubsequence(int N, int A[]) {
    vector<int> dp(N, 1);
    int ans = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(abs(A[i] - A[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

