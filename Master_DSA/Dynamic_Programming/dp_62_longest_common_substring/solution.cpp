// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: `dp[i][j]` is the length of longest common suffix of `S1[0..i-1]` and `S2[0..j-1]`. If `S1[i-1] == S2[j-1]`, `dp[i][j] = dp[i-1][j-1] + 1`. Else, `dp[i][j] = 0`. Max value in `dp` table is answer.

int longestCommonSubstr(string S1, string S2, int n, int m) {
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(S1[i-1] == S2[j-1]) {
                curr[j] = prev[j-1] + 1;
                ans = max(ans, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}

