// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Use `dp[i]` to indicate if `A[0..i]` can be segmented. For each `i`, check all prefixes `A[0..j]`. If `dp[j]` is true and `A[j..i]` is in the dictionary, then `dp[i]` is true.

int wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict(B.begin(), B.end());
    int n = A.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n] ? 1 : 0;
}

